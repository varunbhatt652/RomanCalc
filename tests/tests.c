#include <check.h>

#include "testcases.h"

/* This executes a series of test cases to validate the roman calculator. */
int main(void)
{
    // Create a test suite
	Suite *romancalc = suite_create("romancalc");
	
    // Add the test cases
	suite_add_tcase(romancalc, tc_addition());
	suite_add_tcase(romancalc, tc_subtraction());
	suite_add_tcase(romancalc, tc_roman_to_decimal());
	suite_add_tcase(romancalc, tc_roman_from_decimal());
	
    // Create a runner object that will execute all the previously added test cases
	SRunner *runner = srunner_create(romancalc);
	srunner_run_all(runner, CK_NORMAL);

    // Count how many tests failed, if any
	int fails = srunner_ntests_failed(runner);
	srunner_free(runner);

	return fails;
}
