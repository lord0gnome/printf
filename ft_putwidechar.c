/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 08:43:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/25 10:40:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>

static int	binlen(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n >>= 1;
		i++;
	}
	return (i);

}

char	*ft_putwidechar(wchar_t chr)
{	
	char *str;

	str = setlocale(LC_ALL, "");

	t_mask	n;
	unsigned int v;
	unsigned char octet;

	n.m0 = 0;
	n.m1 = 49280;
	n.m1 = 14712960;
	n.m1 = 4034953344;
	v = chr;
	chr = L'。';
	v = chr;
	n.binlen = binlen(v);
	printf("%d", n.binlen);
	if (n.binlen <= 7)
	{
		octet = chr;
		write(1, &octet, 1);
	}
	else if (n.binlen <= 11)
	{
		n.c1 = (v << 26) >> 26;
		n.c0 = ((v >>6) << 27) >> 27;

		octet = (n.m1 >> 8) | n.c0;
		write(1, &octet, 1);
		octet = ((n.m1 << 24) >> 24) | n.c1;
		write(1, &octet, 1);
	}
	else if (n.binlen <= 16)
	{
		n.c2 = (v << 26) >> 26;
		n.c1 = ((v >> 6) << 26) >> 26;
		n.c0 = ((v >> 12) << 28) >> 28;

		octet = (n.m2 >> 16) | n.c0;
		write(1, &octet, 1);
		octet = ((n.m2 << 16) >> 24) | n.c1;
		write(1, &octet, 1);
		octet = ((n.m2 << 24) >> 24) | n.c2;
		write(1, &octet, 1);
	}
}
int	main(void)
{
ft_putwidechar(122);
}

