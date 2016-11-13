/* Includes -----------------------------------------------------------*/
#include "main.h"
/* Defines ------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------*/
double average(double* vector, unsigned int length);
double minValue(double* vector, unsigned int length);
double maxValue(double* vector, unsigned int length);
double variance(double* vector, unsigned int length);

/* Variables ----------------------------------------------------------*/
static double vect[] = { 0.9501, 0.2311, 0.6068, 0.4860, 0.8913, 0.7621, 0.4565,
		0.0185, 0.8214, 0.4447, 0.6154, 0.7919, 0.9218, 0.7382, 0.1763, 0.4057,
		0.9355, 0.9169, 0.4103, 0.8936, 0.0579, 0.3529, 0.8132, 0.0099, 0.1389,
		0.2028, 0.1987, 0.6038, 0.2722, 0.1988, 0.0153, 0.7468, 0.4451, 0.9318,
		0.4660, 0.4186, 0.8462, 0.5252, 0.2026, 0.6721, 0.8381, 0.0196, 0.6813,
		0.3795, 0.8318, 0.5028, 0.7095, 0.4289, 0.3046, 0.1897, 0.1934, 0.6822,
		0.3028, 0.5417, 0.1509, 0.6979, 0.3784, 0.8600, 0.8537, 0.5936, 0.4966,
		0.8998, 0.8216, 0.6449, 0.8180, 0.6602, 0.3420, 0.2897, 0.3412, 0.5341,
		0.7271, 0.3093, 0.8385, 0.5681, 0.3704, 0.7027, 0.5466, 0.4449, 0.6946,
		0.6213, 0.7948, 0.9568, 0.5226, 0.8801, 0.1730, 0.9797, 0.2714, 0.2523,
		0.8757, 0.7373, 0.1365, 0.0118, 0.8939, 0.1991, 0.2987, 0.6614, 0.2844,
		0.4692, 0.0648, 0.9883 };

/* Main ---------------------------------------------------------------*/
int main(void) {

	/* assignment 1 */
	puts("Running assignment 1 ...");
	double avg = average(vect, sizeof(vect) / sizeof(double));
	printf("The average of the values is: avg = %3.4f\n", avg);
	puts("");
	/* End of assignment 1 */

	/* assignment 2 */
	puts("Running assignment 2 ...");
	double min = minValue(vect, sizeof(vect) / sizeof(double));
	printf("The minimum value found in vector: min = %3.4f\n", min);
	puts("");
	/* End of assignment 2 */

	/* assignment 3 */
	puts("Running assignment 3 ...");
	double max = maxValue(vect, sizeof(vect) / sizeof(double));
	printf("The maximum value found in vector: max = %3.4f\n", max);
	puts("");
	/* End of assignment 3 */

	/* assignment 4 */
	puts("Running assignment 4 ...");
	double var = variance(vect, sizeof(vect) / sizeof(double));
	printf("The variance of the values contained in the vector: variance = %3.4f\n", var);
	puts("");
	/* End of assignment 4 */

	return EXIT_SUCCESS;
}

/* Declarations -------------------------------------------------------*/

/**
 * Calculates the average of the input vector of double's.
 */
double average(double* vector, unsigned int length) {
	double result = 0.0;
	for (int i = 0; i < length; i++) {
		result += vector[0] / (double) length;
	}
	return result;
}

/**
 * Finds and returns the minimum value contained within vector.
 */
double minValue(double* vector, unsigned int length) {
	volatile double min = DBL_MAX;
	for (unsigned int i = 0; i < length; i++) {
		if (vector[i] < min) {
			min = vector[i];
		}
	}

	return min;
}

/**
 * Finds and returns the maximum value contained within vector.
 */
double maxValue(double* vector, unsigned int length) {
	volatile double max = DBL_MIN;
	for (unsigned int i = 0; i < length; i++) {
		if (vector[i] > max) {
			max = vector[i];
		}
	}

	return max;
}

/**
 * Finds and returns the variance of the specified vector.
 */
double variance(double* vector, unsigned int length) {

	if(length == 1) {
		return -1.0;
	}

	volatile double avg = average(vector, length);
	volatile double result = 0.0;
	for(int i=0; i<length; i++) {
		result += ((vector[i] - avg) * (vector[i] - avg))/ (double) length;
	}

	return result;

}
