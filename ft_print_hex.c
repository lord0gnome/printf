/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:39:44 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/13 16:52:49 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int	ft_print_hex(long long n, char caps)
{
	long long bck;
	char *hexstr;
	int len;

	bck = n;
	len = 0;
	if (n == 0)
		ft_putstr("0\0");
	while(bck != 0)
	{
		bck = bck / 16;
		len++;
	}
	bck = n;
	hexstr = (char *)malloc(sizeof(char) * len + 1);
	hexstr[len] = '\0';
	while (bck)
	{
		len--;
		hexstr[len] = (bck % 16) + (48);
		bck /= 16;
	}
	len = 0;
	while (hexstr[len])
	{
		if (hexstr[len] > 57)
			hexstr[len] += (caps ? 7 : 39);
		len++;
	}
	ft_putstr(hexstr);
	return (1);

}
