/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:58:14 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/31 21:09:48 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Look at ft_itoa_base
*/

char	*ft_itoa2(uintmax_t n)
{
	return (ft_itoa_base(n, 10));
}
