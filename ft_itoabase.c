/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:06:07 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/24 15:17:14 by guiricha         ###   ########.fr       */
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
