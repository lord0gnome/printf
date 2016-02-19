/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:10:33 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/19 16:13:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static void	convert_hex(char *str, char caps)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 57 && (str[i] != 'x' && str[i] != 'X'))
			str[i] += (caps ? 7 : 39);
		i++;
	}
}

int			ft_parse_hex(unsigned long long n, char caps, char **str, t_form *info)
{
	long long	bck;
	char		*hexstr;
	int			len;
	int			ret;

	bck = n;
	len = 1;
	if (n == 0)
		info->force = 0;
	if (n == 0 && info->prec == 0)
	{
		hexstr = (char *)malloc(sizeof(char));
		*hexstr = '\0';
		*str = hexstr;
		return (0);
	}
	while (bck /= 16)
		len++;
	ret = ft_det_zeroes(len + (info->force * 2), info, 0);
	hexstr = (char *)malloc(sizeof(char) * (len + ret + (info->force * 2)) + 1);
	hexstr[len + ret + (info->force * 2)] = '\0';
	bck = ret;
	while (ret-- > 0)
		hexstr[ret + (info->force * 2)] = '0';
	if (info->force == 1)
	{
		hexstr[0] = '0';
		hexstr[1] = info->bigsmall;
	}
	ret = bck + len;
	while (len--)
	{
		hexstr[len + bck + (info->force * 2)] = (n % 16) + (48);
		n /= 16;
	}
	convert_hex(hexstr, caps);
	*str = hexstr;
	return (ret + (info->force * 2));
}
