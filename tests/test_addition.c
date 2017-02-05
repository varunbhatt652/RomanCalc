#include <stdlib.h>
#include <check.h>

#include "../romancalc.h"

/* This is a test function to see if addition is working correctly. */
static void test_addition(const char *a, const char *b, const char *expected)
{
	char *result = roman_add(a, b);

    // Check if the obtained result from the program is equal to the expected result,
    // and gives an error if it's not
	ck_assert_msg(strcmp(result, expected) == 0,
            "%s + %s = %s, expected %s", a, b, result, expected);
}

/* Tests if addition is working */
START_TEST(addition_works)
{
	test_addition("I", "I", "II");
	test_addition("II", "II", "IV");
	test_addition("II", "III", "V");
	test_addition("V", "V", "X");
	test_addition("C", "I", "CI");
	test_addition("MM", "M", "MMM");
	test_addition("X", "IV", "XIV");
	test_addition("MC", "CX", "MCCX");
	test_addition("MMMCMXCIX", "I", "MMMM");
}
END_TEST

/* Tests the grouping of multiple roman numerals into one */
START_TEST(grouping)
{
	test_addition("XXX", "XX", "L");
	test_addition("D", "D", "M");
	test_addition("XXXII", "XXV", "LVII");
}
END_TEST

/* Tests if addition's commutative property is working */
START_TEST(commutative_property)
{
	test_addition("V", "I", "VI");
	test_addition("I", "V", "VI");
	test_addition("XII", "V", "XVII");
	test_addition("V", "XII", "XVII");
}
END_TEST

/* Tests if input errors are handled correctly */
START_TEST(input_errors)
{
	test_addition("garbage", "I", "Please supply a valid roman numbers string");
	test_addition("XVI", "g4rb4g3!#%(!", "Please supply a valid roman numbers string");
	test_addition("MMMMMMMMMCMXCIX", "I", "Maximum possible Roman number is 9999");
}
END_TEST

/* Addition of two numbers testcase */
TCase *tc_addition()
{
	TCase *tc = tcase_create("addition");
	tcase_add_test(tc, addition_works);
	tcase_add_test(tc, commutative_property);
	tcase_add_test(tc, grouping);
	tcase_add_test(tc, input_errors);
	return tc;
}
