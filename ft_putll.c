/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:12:12 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 12:41:06 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putll(long long n, char **str)
{
	long long	bck;
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
