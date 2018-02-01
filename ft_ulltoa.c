/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:50:20 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/31 20:06:05 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	count_digits(uintmax_t n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

static char	*allocate_memory(uintmax_t n)
{
	char		*str;
	uintmax_t	i;

	if (n >= 0)
	{
		str = ft_strnew(count_digits(n, 0));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (i < count_digits(n, 0))
			str[i++] = 'X';
	}
	return (str);
}

static char	*string_zero(void)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	return (str);
}

char		*ft_ulltoa(uintmax_t n)
{
	char	*str;
	char	*iter;

	if (n == 0)
		return (string_zero());
	if (n < 0)
		write(1, "ERROR: Unsigned can't go negative\n", 34);
	str = allocate_memory(n);
	if (str == NULL)
		return (NULL);
	iter = str;
	while (*iter)
		iter++;
	iter--;
	if (n < 0)
		n = -n;
	while (n)
	{
		*iter = (n % 10) + '0';
		n /= 10;
		iter--;
	}
	return (str);
}
