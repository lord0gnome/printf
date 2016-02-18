/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 16:15:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 13:32:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_print_bin(long long n)
{
	long long bck;
	char *binstr;
	int len;

	bck = n;
	len = 0;
	if (n == 0)
		ft_putstr("0\0");
	while (bck)
	{
		bck /= 2;
		len++;
	}
	bck = n;
	binstr = (char *)malloc(sizeof(char) * len + 1);
	binstr[len] = '\0';
	while (bck)
	{
		len--;
		binstr[len] = (bck % 2) + 48;
		bck /= 2;
	}
	len = 0;
	while (binstr[len])
	{
		ft_putchar(binstr[len++]);
		if (len % 8 == 0)
			ft_putchar(' ');
	}

	return (len);
}
