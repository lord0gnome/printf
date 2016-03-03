/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:06:07 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/03 14:31:16 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_itoabase(long long n, int base, char caps)
{
	int			len;
	long long	bck;
	char		sign;
	char		*ret;

	if (base > 16 || base < 2)
		return (NULL);
	sign = 0;
	len = 1;
	if (n < 0)
		sign = 1;
	bck = n;
	while (bck /= base)
		len++;
	ret = (char *)malloc(sizeof(char) * len + sign + 1);
	ret[len + sign] = '\0';
	ret[0] = '-';
	while (len--)
	{
		ret[sign + len] = n < 0 ? (-(n % -base)) + 48 : (n % base) + 48;
		n /= base;
		if (ret[sign + len] > 57)
			ret[sign + len] += (caps ? 7 : 39);
	}
	return (ret);
}

char	*ft_itoabaseu(size_t n, int base, char caps)
{
	int			len;
	size_t		bck;
	char		*ret;

	if (base > 16 || base < 2)
		return (NULL);
	len = 1;
	bck = n;
	while (bck /= base)
		len++;
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	while (len--)
	{
		ret[len] = (n % base) + 48;
		n /= base;
		if (ret[len] > 57)
			ret[len] += (caps ? 7 : 39);
	}
	return (ret);
}

char	*ft_itoabaseo(t_form *info, size_t n, int base)
{
	int			len;
	size_t		bck;
	char		*ret;

	if (base > 16 || base < 2)
		return (NULL);
	len = 1;
	bck = n;
	while (bck /= base)
		len++;
	ret = (char *)malloc(sizeof(char) * len + (info->force) + 1);
	ret[(info->force) + len] = '\0';
	bck = n;
	if (info->force == 1)
		ret[0] = '0';
	while (len--)
	{
		ret[len + (info->force)] = (n % base) + 48;
		n /= base;
	}
	if (bck == 0 && info->force == 1)
		ret[0 + info->force] = '\0';
	return (ret);
}

char	*ft_itoabasex(t_form *i, size_t n, int base, char caps)
{
	int			len;
	size_t		bck;
	char		*ret;

	if (base > 16 || base < 2)
		return (NULL);
	len = 1;
	bck = n;
	while (bck /= base)
		len++;
	if (n == 0)
		i->force = 0;
	ret = (char *)malloc(sizeof(char) * len + (i->force * 2) + 1);
	ret[(i->force * 2) + len] = '\0';
	bck = n;
	if (i->force == 1)
	{
		ret[0] = '0';
		ret[1] = caps ? 'X' : 'x';
	}
	while (len--)
	{
		ret[len + (i->force * 2)] = (n % base) + 48;
		n /= base;
		if (ret[len + (i->force * 2)] > 57)
			ret[len + (i->force * 2)] += (caps ? 7 : 39);
	}
	if (bck == 0 && i->force == 1)
		ret[0 + (i->force * 2)] = '\0';
	return (ret);
}

char	*ft_itoabasep(t_form *i, size_t n, int base, char caps)
{
	int			len;
	size_t		bck;
	char		*ret;

	if (base > 16 || base < 2)
		return (NULL);
	len = 1;
	bck = n;
	while (bck /= base)
		len++;
	ret = (char *)malloc(sizeof(char) * len + (i->force * 2) + 1);
	ret[(i->force * 2) + len] = '\0';
	if (i->force == 1)
	{
		ret[0] = '0';
		ret[1] = caps ? 'X' : 'x';
	}
	while (len--)
	{
		ret[len + (i->force * 2)] = (n % base) + 48;
		n /= base;
		if (ret[len + (i->force * 2)] > 57)
			ret[len + (i->force * 2)] += (caps ? 7 : 39);
	}
	return (ret);
}


