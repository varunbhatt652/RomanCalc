#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "romancalc.h"

const int ERR = -1;

/*********************************************************************************************
 *                                        Roman Words                                        *
 *                                                                                           *
 *********************************************************************************************/
/* Returns the roman word with the biggest numeral. */
static const RomanWord *biggest_numeral(void)
{
	return &ROMAN_WORDS[0];
}

/* Returns the next roman word that is smaller than the supplied roman word. */
static const RomanWord *next_smaller_numeral(const RomanWord *word)
{
	return word < &ROMAN_WORDS[sizeof(ROMAN_WORDS) / sizeof(RomanWord) - 1] ? word + 1 : 0;
}

/*********************************************************************************************
 *                                                                                           *
 *                                Static auxiliary functions                                 *
 *                                                                                           *
 *********************************************************************************************/

/* Checks if a decimal number converted by the calculator is equal to the expected roman equivalent. */
static bool validate_input(int number, const char *expected)
{
	char *roman = roman_from_decimal(number);
	bool result = strcmp(roman, expected) == 0;
	return result;
}

/* Sum the roman word numerals and convert the result into a decimal number */
static int sum_roman_numerals(const char *numerals)
{
	int sum = 0;
    int length;

    // Iterate over the roman words, from biggest to smallest, in order to find the biggest
    // value that matches the numeral pointed by numerals. When it is found, the value is
    // added to sum, and the numeral pointer is incremented by the size of the numeral found.
    // The process is done when numeral points to NULL (end of string).
	for (const RomanWord *word = biggest_numeral(); word; word = next_smaller_numeral(word))
	{
        length = strlen(word->numeral);
		while (strncmp(numerals, word->numeral, length) == 0)
		{
			sum += word->number;
			numerals += length;
		}
	}
	return sum;
}

/* Compose part of the roman string through concatenation */
static int concatenate_word(RomanWord word, int remainder, char *result)
{
	while (remainder >= word.number)
	{
		strcat(result, word.numeral);
		remainder -= word.number;
	}
	return remainder;
}

/* Make a roman string from decimal numbers by concatenating the numerals */
static void make_roman_string(const int number, char *result)
{
	int remainder = number;

    // Iterate over the roman words, from biggest to smallest, in order to find the biggest
    // numeral that matches the supplied number. When it is found, the word is concatenated
    // to result, and the remainder is decremented by the size of the numeral found.
    // The process is done when numeral points to NULL (end of string).
	for (const RomanWord *word = biggest_numeral(); word; word = next_smaller_numeral(word))
	{
		remainder = concatenate_word(*word, remainder, result);
	}
}

/*********************************************************************************************
 *                                                                                           *
 *                                Conversion functions                                       *
 *                                                                                           *
 *********************************************************************************************/

/* Convert roman string to decimal number */
int roman_to_decimal(const char *roman)
{
	if (!roman) return ERR;

	int number = sum_roman_numerals(roman);
	bool valid_input = validate_input(number, roman);

	return valid_input ? number : ERR;
}

/* Convert decimal number to roman string */
char *roman_from_decimal(const int number)
{
	static char roman[1024];
    memset(roman, 0, sizeof(roman));

	if (number < 1) {
        return strcat(roman, "Zero and negative numbers are not allowed in Roman");
    }
	else if (number > 9999) {
        return strcat(roman, "Maximum possible Roman number is 9999");
    }

	make_roman_string(number, roman);
	return roman;
}

/*********************************************************************************************
 *                                                                                           *
 *                                Addition and subtraction                                   *
 *                                                                                           *
 *********************************************************************************************/

/* Add two roman numbers */
char *roman_add(const char *a, const char *b)
{
    // Convert the roman numerals to decimal
	int a_num = roman_to_decimal(a);
	int b_num = roman_to_decimal(b);

	if (a_num == ERR || b_num == ERR)
		return "Please supply a valid roman numbers string";

    // Sum the decimal equivalents
	int result = a_num + b_num;

    // Convert the result back to roman and print it
	char *sum = roman_from_decimal(result);
    printf("Decimal: %d + %d = %d\n", a_num, b_num, result);
    printf("Roman  : %s + %s = %s\n\n", a, b, sum);
	return sum;
}

/* Subtract two roman numbers */
char *roman_subtract(const char *a, const char *b)
{
    // Convert the roman numerals to decimal
	int a_num = roman_to_decimal(a);
	int b_num = roman_to_decimal(b);

	if (a_num == ERR || b_num == ERR)
		return "Please supply a valid roman numbers string";

    // Subtract the decimal equivalents
	int result = a_num - b_num;

    // Convert the result back to roman and print it
	char *diff = roman_from_decimal(result);
    printf("Decimal: %d - %d = %d\n", a_num, b_num, result);
    printf("Roman  : %s - %s = %s\n\n", a, b, diff);
	return diff;
}

