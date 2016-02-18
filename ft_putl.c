/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:12:24 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 16:12:56 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putl(long n, char **str)
{
	long		bck;
	int			len;
	char		sign;
	int			lenbck;
	char 		*ret;

	len = 1;
	sign = (n < 0 ? 1 : 0);
	n = (sign == 1 ? -n : n);
	bck = n;
	while (bck /= 10)
		len++;
	ret = (char *)malloc(sizeof(char) * (len + sign + 1));
	ret[0] = '-';
	ret[len + sign] = '\0';
	lenbck = len;
	while (len--)
	{
		ret[len + sign] = n % 10 + '0';
		n /= 10;
	}
	*str = ret;
	return (lenbck + sign);
}
