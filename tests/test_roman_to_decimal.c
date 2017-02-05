#include <stdint.h>
#include <check.h>

#include "../romancalc.h"

/* This is a test function to see if roman to decimal function is working correctly. */
static void roman_to_decimal_test(const char* roman, const int expected)
{
	int result = roman_to_decimal(roman);

    // Check if the obtained result from the program is equal to the expected result,
    // and gives an error if it's not
	ck_assert_msg(result == expected,
            "\n%s in decimal: %d, but expected %d", roman, expected, result);
}

/* This is a conversion test */
START_TEST(conversion_test)
{
	roman_to_decimal_test("I", 1);
	roman_to_decimal_test("II", 2);
	roman_to_decimal_test("III", 3);
	roman_to_decimal_test("IV", 4);
	roman_to_decimal_test("V", 5);
	roman_to_decimal_test("VI", 6);
	roman_to_decimal_test("VII", 7);
	roman_to_decimal_test("VIII", 8);
	roman_to_decimal_test("IX", 9);
	roman_to_decimal_test("X", 10);
	roman_to_decimal_test("XIV", 14);
	roman_to_decimal_test("XV", 15);
	roman_to_decimal_test("XX", 20);
	roman_to_decimal_test("XXX", 30);
	roman_to_decimal_test("XL", 40);
	roman_to_decimal_test("L", 50);
	roman_to_decimal_test("LX", 60);
	roman_to_decimal_test("C", 100);
	roman_to_decimal_test("D", 500);
	roman_to_decimal_test("DCCCLXXXVIII", 888);
	roman_to_decimal_test("M", 1000);
	roman_to_decimal_test("MI", 1001);
}
END_TEST

/* Tests if input errors are handled correctly */
START_TEST(input_errors)
{
	roman_to_decimal_test("S", -1);
	roman_to_decimal_test("XVB",-1);
	roman_to_decimal_test("aoekf", -1);
	roman_to_decimal_test("138", -1);
	roman_to_decimal_test("MMXM3", -1);
	roman_to_decimal_test("IIII", -1);
	roman_to_decimal_test("VIV", -1);
	roman_to_decimal_test("VVV", -1);
	roman_to_decimal_test("XXXX", -1);
	roman_to_decimal_test("DDD", -1);
	roman_to_decimal_test("LLLL", -1);
	roman_to_decimal_test("CCCC", -1);
	roman_to_decimal_test("CCM", -1);
	roman_to_decimal_test(NULL, -1);
}
END_TEST

/* Roman to decimal conversion testcase */
TCase *tc_roman_to_decimal()
{
	TCase *tc = tcase_create("roman to decimal");
	tcase_add_test(tc, conversion_test);
	tcase_add_test(tc, input_errors);
	return tc;
}
