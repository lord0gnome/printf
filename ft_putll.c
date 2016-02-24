/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:12:12 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/24 11:19:43 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putll(long long n, char **str, t_form *info)
{
	long long	bck;
	int			len;
	char		sign;
	int			lenbck;
	char 		*ret;

	len = 1;
	sign = (n < 0  || info->plus  || info->space ? 1 : 0);
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
	lenbck = ft_det_zeroes(len, info, sign);
	ret = (char *)malloc(sizeof(char) * (len + sign + lenbck + 1));
	ret[0] = (info->plus && n >= 0 ? '+' : '-');
	if (info->space == 1 && n >= 0)
		ret[0] = ' ';
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

int	ft_putllu(long long unsigned n, char **str, t_form *info)
{
	long long	bck;
	int			len;
	int			lenbck;
	char 		*ret;

	len = 1;
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
	lenbck = ft_det_zeroes(len, info, 0);
	ret = (char *)malloc(sizeof(char) * (len + lenbck + 1));
	ret[len + lenbck] = '\0';
	bck = lenbck;
	while (lenbck-- > 0)
		ret[lenbck] = '0';
	lenbck = bck + len;
	while (len--)
	{
		ret[len + bck] = n % 10 + '0';
		n /= 10;
	}
	*str = ret;
	return (lenbck);
}
