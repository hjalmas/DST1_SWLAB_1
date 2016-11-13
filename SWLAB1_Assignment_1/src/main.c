/* Includes -----------------------------------------------------------*/
#include "main.h"
/* Defines ------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------*/
double PI_estimator(int nMembers);
int findMinPIMembers(unsigned prec);

/* Variables ----------------------------------------------------------*/
static const double PI_nom = 3.14159;

/* Main ---------------------------------------------------------------*/
int main(void) {

	/* assignment a): Estimate pi */
	puts("Running assignment a) ...");
	double pi = 0.0;
	double sign = 1.0;
	double N = 99;
	for (double denom = 1; denom <= N; denom += 2, sign *= -1.0) {
		pi += sign * (1 / denom);
	}
	pi *= 4;
	printf("The %.0f first terms yields: pi ~ %f\n", N / 2 + 1, pi);
	puts("");
	/* End of assigment a) */

	/* assignment b) */
	puts("Running assignment b) ...");
	int terms = 50;
	printf("The %d first terms yields: pi ~ %f\n", terms, PI_estimator(terms));
	puts("");
	/* End of assignment b) */

	/* assignment c) */
	puts("Running assignment c) ...");
	int mem = findMinPIMembers(1);
	puts("");
	/* End of assignment c) */

	return EXIT_SUCCESS;
}

/* Declarations -------------------------------------------------------*/

/**
 * Returns an approximation of pi.
 * If a non-valid argument is detected the function will return -1.0
 * valid arguments is the positive integers (0 is not included).
 */
double PI_estimator(int nMembers) {
	if (nMembers <= 0) { //Argument checking
		return -1.0;
	}

	volatile double pi = 0.0;
	volatile double sign = 1.0;
	for (double denom = 1; denom <= 2 * nMembers - 1;
			denom += 2, sign *= -1.0) {
		pi += sign * (1 / denom);
	}
	return pi * 4;
}

/**
 * returns the minimum number of members needed to stay within +/- prec %
 * of a surrounding to pi.
 */
int findMinPIMembers(unsigned prec) {

	/* Calculate minimum and maximum values of pi based on specified precision*/
	volatile double maxError = ((double) prec / 100) * PI_nom;

	/* Find a value within the range of precision */
	volatile int memberGuess = 1;
	volatile double error = 10000000000.0;
	/* Double the number of members to include for each iteration */
	while (fabs(error = PI_nom - PI_estimator(memberGuess)) > maxError) {
		memberGuess *= 2;
	}

	/* now back down to the smallest number of members */
	while (fabs(error = PI_nom - PI_estimator(memberGuess)) <= maxError) {
		memberGuess--;
	}
	memberGuess++;

	return memberGuess;
}
