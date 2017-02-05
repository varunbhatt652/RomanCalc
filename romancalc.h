#ifndef ROMAN_CALCULATOR_H
#define ROMAN_CALCULATOR_H

typedef struct RomanWord {
	int number;
	char numeral[3];
} RomanWord;

static const RomanWord ROMAN_WORDS[] = {
	{ 1000, "M" },	{ 900, "CM" }, { 500,  "D" }, { 400, "CD" },
    { 100,  "C" },  { 90,  "XC" }, { 50,   "L" }, { 40,  "XL" },
    { 10,   "X" },  { 9,   "IX" }, { 5,    "V" }, { 4,   "IV" },
	{ 1,    "I" },
};

/* Convert to Roman from Decimal */
char *roman_from_decimal(const int number);

/* Convert to Decimal from Roman */
int roman_to_decimal(const char *numeral);

/* Adds two Roman numbers */
char *roman_add(const char *a, const char *b);

/* Subtracts two Roman numbers */
char *roman_subtract(const char *a, const char *b);

#endif /* ROMAN_CALCULATOR_H */
