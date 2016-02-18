/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:12:12 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 16:16:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	det_zeros(int len, t_form *info)
{
	int n;

	n = 0;
	if ((info->zero && info->width > 0) || info->prec > 0)
	{
		if (info->width > 0 && info->zero)
		{
			n = info->width - len;
			info->width = -1;
		}
		else if (info->prec > 0)
		{
			n = info->prec - len;
			info->prec = -1;
		}
	}
	if (n < 0)
		n = 0;
	return (n);
}

int	ft_putll(long long n, char **str, t_form *info)
{
	long long	bck;
	int			len;
	char		sign;
	int			lenbck;
	char 		*ret;

	len = 1;
	sign = (n < 0  || info->plus ? 1 : 0);
	bck = n;
	if (n == 0 && info->prec == 0)
	{
		ret = (char *)malloc(sizeof(char));
		*ret = '\0';
		*str = ret;
		return (0);
	}
	while (bck /= 10)
		len++;
	lenbck = det_zeros(len, info);
	ret = (char *)malloc(sizeof(char) * (len + sign + lenbck + 1));
	ret[0] = (info->plus && n >= 0? '+' : '-');
	n = (n < 0 ? -n : n);
	ret[len + sign + lenbck] = '\0';
	bck = lenbck;
	while (lenbck-- > 0)
		ret[lenbck + sign] = '0';
	lenbck = bck + len;
	while (len--)
	{
		ret[len + sign + bck] = n % 10 + '0';
		n /= 10;
	}
	*str = ret;
	return (lenbck + sign);
}
