#include "ft_printf.h"

int main()
{
	int n;
	int s;

	//	n = ft_printf("%d\n", 0);
	//	printf("result: %d\n", n);

	//	n = ft_printf("%#d\n", 1);
	//	printf("Number sign: %#d\n", 1);
	/*
	printf("0 flag with no min width\n");
	printf("EXPECTED: '%0d'\n", 45);
	ft_printf("RESULT: '%0d'\n", 45);
	printf("0 flag with min width > num width\n");
	n = printf("EXPECTED: '%04d'\n", 22);
	s= ft_printf("ACTUAL: '%04d'\n", 22);
	printf("EXPECTED return: %d\n", n);
	printf("ACTUAL return: %d\n", s);
	n = ft_printf("Width: %3.3d\n", 2);
	printf("Width: %5.4d\n", 235);
	printf("Width: %04d\n", 245);
	printf("Width: %4d\n", 267);
	*/
	//	n = ft_printf("%x\n", 0);
	//	printf("result: %x\n", n);

	//	n = ft_printf("%#d\n", 1);
	//	printf("Number sign: %#d\n", 1);

	printf("beginning test for ft_printf with octal conversion\n\n");

	intmax_t len2 = 0;
	n = printf("TESTING 145640 -> %o\n", 145640);
	ft_putchar('\n');
	len2 = ft_printf("TEST -> %o", 145640);
	//printf("n -> %d\t n2 -> %d\n", n, len2);

	// Emoji test.
	//setlocale(LC_ALL,"");
    //printf("Let's go to the cantina and eat some %lc\n", 0x1F35D);
	/*
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("***************************BEGIN UNIT TESTS******************************\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

	t_bag *bag = 0;
	char *format = 0;
	int	number_of_printed_characters = 0;
	int n = 0;
	va_list dummy;
	char *expected = 0;
	char *str = 0;
	char pad_character = 0;
	*/
	/*
	printf("***********************HANDLE_PERCENT PARSING TESTS***************************\n");
	printf("For these parsing tests to work, make sure to remember to set return type from \"void\" to \"t_bag *\" on function \"handle_percent\". Set it back to void when you are done.\n");


	format = "%+d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("PLUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->plus, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	printf("\n");

	format = "%-d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	printf("\n");

	format = "%-d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	printf("\n");

	format = "%+300.400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "1";
	printf("PLUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->plus, expected);
	expected = "300";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "400";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%.400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "-1";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "400";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "400";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "-1";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%Dd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "-1";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "-1";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "D";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%-03.5hhdHello";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "0";
	printf("ZERO FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->zero, expected);
	expected = "3";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "5";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "hh";
	printf("LENGTH_MODIFIER IS: %s, RESULT IS SUPPOSED TO BE: %s\n", bag->length_modifier, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "H";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%03.5zdHello";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "1";
	printf("ZERO FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->zero, expected);
	expected = "3";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "5";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "z";
	printf("LENGTH_MODIFIER IS: %s, RESULT IS SUPPOSED TO BE: %s\n", bag->length_modifier, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "H";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%3.3%asdf";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "3";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "3";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "";
	printf("LENGTH_MODIFIER IS: %s, RESULT IS SUPPOSED TO BE: %s\n", bag->length_modifier, expected);
	expected = "%";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->format_conversion, expected);
	expected = "a";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	printf("***********************PAD_LEFT TESTS***************************\n");
	str = "TEST";
	n = 5;
	pad_character = ' ';
	expected = " TEST";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	str = "100";
	n = 10;
	pad_character = '0';
	expected = "0000000100";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	str = "100";
	n = 3;
	pad_character = '0';
	expected = "100";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	printf("***********************PAD_RIGHT TESTS***************************\n");
	str = "TEST";
	n = 5;
	pad_character = '0';
	expected = "TEST0";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	str = "100";
	n = 10;
	pad_character = ' ';
	expected = "100       ";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	str = "100";
	n = 3;
	pad_character = '0';
	expected = "100";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	printf("***********************CUT_LEFT TESTS***************************\n");
	str = "100";
	n = 2;
	expected = "0";
	printf("CUT_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_left(str, n), expected);

	str = "100";
	n = 5;
	expected = "";
	printf("CUT_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_left(str, n), expected);

	printf("***********************CUT_RIGHT TESTS***************************\n");
	str = "100";
	n = 2;
	expected = "1";
	printf("CUT_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_right(str, n), expected);

	str = "100";
	n = 5;
	expected = "";
	printf("CUT_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_right(str, n), expected);
	*/

	setlocale(LC_ALL,"");
}
