/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:10:33 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 13:10:33 by guiricha         ###   ########.fr       */
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
		if (str[i] > 57)
			str[i] += (caps ? 7 : 39);
		i++;
	}
}

int			ft_parse_hex(long long n, char caps)
{
	long long	bck;
	char		*hexstr;
	int			len;
	int			ret;

	bck = n;
	len = 1;
	while (bck / 16)
	{
		len++;
		bck /= 16;
	}
	hexstr = (char *)malloc(sizeof(char) * len + 1);
	hexstr[len] = '\0';
	ret = len;
	while (len)
	{
		len--;
		hexstr[len] = (n % 16) + (48);
		n /= 16;
	}
	convert_hex(hexstr, caps);
	ft_putstr(hexstr);
	return (ret);
}
