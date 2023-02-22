#include <stdio.h>
#include <assert.h>
#include "outlier_calculator.h"


#define DATA_LENGTH_1 1
#define MAX_CHANGE_RATE_1 3

#define DATA_LENGTH_2 4
#define MAX_CHANGE_RATE_2 3

#define DATA_LENGTH_3 7
#define MAX_CHANGE_RATE_3 12

#define DATA_LENGTH_4 3
#define MAX_CHANGE_RATE_4 20

#define DATA_LENGTH_5 3
#define MAX_CHANGE_RATE_5 45

#define DATA_LENGTH_6 8
#define MAX_CHANGE_RATE_6 100



int compare_output(int* input, int* output, int data_length) {
    int i;
    for(i = 0; i < data_length; i++) {
        if (input[i] != output[i]) return 0;
    }
    return 1;
}


int compare_outlier_stats(stat_t* outlier_stats, stat_t* expected_outlier_stats){
    if (outlier_stats->count != expected_outlier_stats->count){
        return 0;
    }
    if(outlier_stats->count){
        if (outlier_stats->min != expected_outlier_stats->min){
            return 0;
        }
        if (outlier_stats->max != expected_outlier_stats->max){
            return 0;
        }
        if (outlier_stats->average != expected_outlier_stats->average){
            return 0;
        }
    }
    return 1;
}


int calculate_outliers(
    int* input, int* output,
    int* expected_output,
    stat_t* expected_outlier_stats,
    int data_length,
    int max_change_rate)
{

    stat_t outlier_stats;
    calculate(input, output, data_length, max_change_rate, &outlier_stats);
    if(!compare_output(output, expected_output, data_length)){
        return 0;
    }
    if(!compare_outlier_stats(&outlier_stats, expected_outlier_stats)){
        return 0;
    }
    return 1;
}


int test_with_array_length_1(){
    int input[DATA_LENGTH_1] = {2};
    int output[DATA_LENGTH_1] = {0};
    int expected_output[DATA_LENGTH_1] = {2};
    stat_t expected_outlier_stats = {.count = 0};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_1,
        MAX_CHANGE_RATE_1
    );
}


int test_with_array_length_2(){
    int input[DATA_LENGTH_2] = {1,2,6500,4};
    int output[DATA_LENGTH_2] = {0};
    int expected_output[DATA_LENGTH_2] = {1,2,3,4};
    stat_t expected_outlier_stats = {.count = 1, .min = 6500, .max = 6500, .average = 6500};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_2,
        MAX_CHANGE_RATE_2
    );
}


int test_with_array_length_3(){
    int input[DATA_LENGTH_3] = {3,5,11,65,15,34,20};
    int output[DATA_LENGTH_3] = {0};
    int expected_output[DATA_LENGTH_3] = {3, 5, 11, 12, 15, 16, 20};
    stat_t expected_outlier_stats = {.count = 2, .min = 34, .max = 65, .average = 49.5};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_3,
        MAX_CHANGE_RATE_3
    );
}


int test_with_array_length_4(){
    int input[DATA_LENGTH_4] = {10,40,20};
    int output[DATA_LENGTH_4] = {0};
    int expected_output[DATA_LENGTH_4] = {10,11,20};
    stat_t expected_outlier_stats = {.count = 1, .min = 40, .max = 40, .average = 40};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_4,
        MAX_CHANGE_RATE_4
    );
}


int test_with_array_length_5(){
    int input[DATA_LENGTH_5] = {4,5,3900};
    int output[DATA_LENGTH_5] = {0};
    int expected_output[DATA_LENGTH_5] = {4,5,6};
    stat_t expected_outlier_stats = {.count = 1, .min = 3900, .max = 3900, .average = 3900};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_5,
        MAX_CHANGE_RATE_5
    );
}


int test_with_array_length_6(){
    int input[DATA_LENGTH_6] = {23,23,34,43,74,4675,4324,100};
    int output[DATA_LENGTH_6] = {0};
    int expected_output[DATA_LENGTH_6] = {23,23,34,43,74,75,76,100};
    stat_t expected_outlier_stats = {.count = 3, .min = 4324, .max = 4675, .average = 4499.5};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_6,
        MAX_CHANGE_RATE_6
    );
}


int test_with_array_length_7(){
    int input[DATA_LENGTH_6] = {23,23,34,43,74,4675,4324,100};
    int output[DATA_LENGTH_6] = {0};
    int expected_output[DATA_LENGTH_6] = {23,23,34,43,74,75,76,100};
    stat_t expected_outlier_stats = {.count = 3, .min = 4324, .max = 4675, .average = 4499.5};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_6,
        MAX_CHANGE_RATE_6
    );
}


int test_with_array_length_8(){
    int input[DATA_LENGTH_6] = {23,23,34,43,74,4675,4324,100};
    int output[DATA_LENGTH_6] = {0};
    int expected_output[DATA_LENGTH_6] = {23,23,34,43,74,75,4324,100};
    stat_t expected_outlier_stats = {.count = 2, .min = 4324, .max = 4675, .average = 4499.5};

    return calculate_outliers(
        input,
        output,
        expected_output,
        &expected_outlier_stats,
        DATA_LENGTH_6,
        MAX_CHANGE_RATE_6
    );
}


int main()
{
    assert(test_with_array_length_1());
    assert(test_with_array_length_2());
    assert(test_with_array_length_3());
    assert(test_with_array_length_4());
    assert(test_with_array_length_5());
    assert(!test_with_array_length_6());
    assert(!test_with_array_length_7());
    assert(!test_with_array_length_8());

    printf("All test cases passed! \n");
}
