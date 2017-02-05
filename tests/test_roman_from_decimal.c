#include <stdlib.h>
#include <check.h>

#include "../romancalc.h"

/* This is a test function to see if decimal to roman function is working correctly. */
static void roman_from_decimal_test(const int number, const char *expected)
{
	char *result = roman_from_decimal(number);

    // Check if the obtained result from the program is equal to the expected result,
    // and gives an error if it's not
	ck_assert_msg(strcmp(result, expected) == 0,
            "\n%d to roman: %s, but expected %s", number, result, expected);
}

/* This is a conversion test */
START_TEST(conversion_test)
{
	roman_from_decimal_test(1, "I");
	roman_from_decimal_test(2, "II");
	roman_from_decimal_test(3, "III");
	roman_from_decimal_test(4, "IV");
	roman_from_decimal_test(5, "V");
	roman_from_decimal_test(6, "VI");
	roman_from_decimal_test(7, "VII");
	roman_from_decimal_test(8, "VIII");
	roman_from_decimal_test(9, "IX");
	roman_from_decimal_test(10, "X");
	roman_from_decimal_test(14, "XIV");
	roman_from_decimal_test(15, "XV");
	roman_from_decimal_test(20, "XX");
	roman_from_decimal_test(30, "XXX");
	roman_from_decimal_test(40, "XL");
	roman_from_decimal_test(50, "L");
	roman_from_decimal_test(60, "LX");
	roman_from_decimal_test(100, "C");
	roman_from_decimal_test(500, "D");
	roman_from_decimal_test(888, "DCCCLXXXVIII");
	roman_from_decimal_test(1000, "M");
	roman_from_decimal_test(1001, "MI");
}
END_TEST

/* Tests if input errors are handled correctly */
START_TEST(input_errors)
{
	roman_from_decimal_test(0, "Zero and negative numbers are not allowed in Roman");
	roman_from_decimal_test(-1, "Zero and negative numbers are not allowed in Roman");
	roman_from_decimal_test(-100, "Zero and negative numbers are not allowed in Roman");
	roman_from_decimal_test(10000, "Maximum possible Roman number is 9999");
	roman_from_decimal_test(10001, "Maximum possible Roman number is 9999");
	roman_from_decimal_test(999999, "Maximum possible Roman number is 9999");
}
END_TEST

/* Decimal to roman conversion testcase */
TCase *tc_roman_from_decimal()
{
	TCase *tc = tcase_create("roman from decimal");
	tcase_add_test(tc, conversion_test);
	tcase_add_test(tc, input_errors);
	return tc;
}
