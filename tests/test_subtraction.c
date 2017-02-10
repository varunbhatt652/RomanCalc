#include <stdlib.h>
#include <check.h>

#include "../romancalc.h"

/* This is a test function to see if subtraction is working correctly. */
static void test_subtraction(const char *a, const char *b, const char *expected)
{
	char *result = roman_subtract(a, b);
    // Check if the obtained result from the program is equal to the expected result,
    // and gives an error if it's not
	ck_assert_msg(strcmp(result, expected) == 0,
            "%s - %s = %s, expected %s", a, b, result, expected);
}



/* Tests if subtraction is working */
START_TEST(subtraction_works)
{
	test_subtraction("II", "I", "I");
	test_subtraction("IV", "I", "III");
	test_subtraction("V", "I", "IV");
	test_subtraction("X", "I", "IX");
	test_subtraction("L", "X", "XL");
	test_subtraction("C", "X", "XC");
	test_subtraction("CC", "C", "C");
	test_subtraction("D", "C", "CD");
	test_subtraction("M", "C", "CM");
	test_subtraction("MMM", "X", "MMCMXC");
}
END_TEST

/* Tests if input errors are handled correctly */
START_TEST(input_errors)
{
	test_subtraction("X", "X", "Zero and negative numbers are not allowed in Roman");
	test_subtraction("X", "XI", "Zero and negative numbers are not allowed in Roman");
	test_subtraction("huh", "I", "Please supply a valid roman numbers string");
	test_subtraction("LL", "I", "Please supply a valid roman numbers string");
    test_subtraction("XVI", "g4rb4g3!#%(!", "Please supply a valid roman numbers string");
    test_subtraction("g4rb4g3!#%(!", "XVI", "Please supply a valid roman numbers string");
}
END_TEST

/* Subtraction of two numbers testcase */
TCase *tc_subtraction(void)
{
	TCase *tc = tcase_create("subtraction");	
	tcase_add_test(tc, subtraction_works);
	tcase_add_test(tc, input_errors);
	return tc;
}
