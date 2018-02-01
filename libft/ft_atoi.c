/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <husui@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:18:33 by husui             #+#    #+#             */
/*   Updated: 2018/01/31 22:19:18 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	sign = (*str == '-') * -2 + 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	return (result * sign);
}
