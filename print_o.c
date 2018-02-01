#include "ft_printf.h"
# define INIT int i; int tmp; int len; intmax_t oct; int a; char *number;

/*
Study reference for bitshiftting
int		oct(unsigned long long x) {
	char buf[99999];
	char *z = buf[99999];

	while (x > INTMAX_MAX)
		{
			*--z = '0' + (x & 7);
			x >>= 3;
		}
}

char	*hex() {
	static char memes[] = {'0123456789abcdef'}
	char bu[99999];
	char *z = buf[99999];
	while(x) {
		*--z = memes[x & 15];
		x >>= 4;
	}
	return z;
}

union u_arg
{
	unint64_t i;
	long double f;
	uintptr_t p;
}

union u_arg *num;

num.i;


0    0      0    0      0    0      4    f
0000 0000 | 0000 0000 | 0000 0000 | 0100 1111 66
									0000 1111
											f
											4

*/

static char	 *print_octal(char *str, int *l)
{
	/*
		Most work with unsigned and decimals only
		// tmp variable for the original decimal value
		unsigned long tmp_var;
		// Have the decimal and a counter that will store our arguments
		unsigned long value;
		int len;
		-> While the bag->format_conversion is 'o' or 'O' && string is not '\0'
			1) Transform value to octal
				a) Use the tmp variable to store the remainder of the result from the decimal (decimal % 8)
				b) Divide your tmp to 8 (tmp /= 8)
			2) Increment your iteration
		-> if there is a '-', then cast it to a unsigned integer
		-> Result with *i and tmp
	*/
	INIT;
	i = 0;
	tmp = 0;
	oct = 0;
	a = 0;
	len = ft_strlen(str);
	number = ft_strnew(len + 1);
	while (a < len)
		number[a++] = '\0';
	oct = ft_atoi(str);
	if (oct == 0)
		number[i] = '\0';
	while (oct > 0)
	{
		tmp = oct % 8;
		oct /= 8;
		number[i++] = tmp + '0';
	}
	number[i] = '\0';
	ft_strrev(number);
	return (number);
}

void		print_o(t_bag *bag, va_list args, int *i)
{
	int len;
	char *str;
	char *res;
	intmax_t input;

	input = va_arg(args, intmax_t);
	// if (input < 0)
	// 	input = (uintmax_t)input;
	str = ft_intmax_toa(input);
	printf("%s\n", str);
	len = ft_strlen(str);
	res = print_octal(str, &len);
	*i += len;
	write(1, res, len);
}
