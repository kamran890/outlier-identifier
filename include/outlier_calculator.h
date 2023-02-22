typedef struct{
	int count;			///< Number of outliers
	int max;			///< Maximum outlier value found in input data
	int min;			///< Minimum outlier value found in input data
	float average;		///< Average value of outliers
}stat_t;


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
);
