#include "outlier_calculator.h"


/// @brief
/// @param[in] input_data Input data array, first sample is assumed to be “correct”
/// @param[out] output_data Filtered and fitted output
/// @param[in] input_data_length Length of the input array
/// @param[in] max_change_rate limit that function should use to detect "outliers" in input data
/// @param[out] outlier_stats output statistics
void calculate(int const* const input_data,
	int* output_data,
	int input_data_length,
	int max_change_rate,
	stat_t* outlier_stats
){
	outlier_stats->count = 0;

	for(int i=0; i<input_data_length; i++){
		if(i>0){
			// Identify outlier
			if ((input_data[i] - output_data[i-1]) > max_change_rate){
				outlier_stats->count++;

				if(outlier_stats->count == 1){
					// For first outlier
					outlier_stats->min = input_data[i];
					outlier_stats->max = input_data[i];
					outlier_stats->average = input_data[i];
				}
				else{
					// Identify if the new outlier is max
					if(input_data[i] > outlier_stats->max){
						outlier_stats->max = input_data[i];					
					}

					// Identify if the new outlier is min
					if (input_data[i] < outlier_stats->min){
						outlier_stats->min = input_data[i];
					}

					// Calculate average of outliers
					outlier_stats->average = (outlier_stats->average + input_data[i])/outlier_stats->count;
				}
				// Put the fitted datapoint in output to replace outlier
				output_data[i] = output_data[i-1] + 1;
			}else{
				// Put datapoint in output if it is not outlier
				output_data[i] = input_data[i];
			}
		}else{
			// First datapoint will go to output as it is
			output_data[i] = input_data[i];
		}
	}
}
