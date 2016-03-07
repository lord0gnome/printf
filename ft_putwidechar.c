/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 08:43:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/07 15:12:10 by guiricha         ###   ########.fr       */
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

int	get_wstrlen(wchar_t *str, int prec)
{	
	int	ret;
	t_mask	n;
	unsigned int v;

	ret = 0;
	if (str == NULL)
		return (6);
	while (42)
	{
		v = *str;
		n.binlen = binlen(v);
		if (v == 0)
			break;
		if (n.binlen <= 7 && (prec == -1 || (ret ) < prec))
			ret += 1;
		else if (n.binlen <= 11 && (prec == -1 || (ret + 1) < prec))
			ret += 2;
		else if (n.binlen <= 16 && (prec == -1 || (ret + 2) < prec))
			ret += 3;
		else if (prec == -1 || (ret + 3) < prec)
			ret += 4;
		if (!*++str)
			break;
	}
	return (ret);
}


int	ft_putwidestr(wchar_t *str, int prec)
{	
	int	ret;
	t_mask	n;
	unsigned int v;
	unsigned char octet;

	n.m0 = 0;
	n.m1 = 49280;
	n.m2 = 14712960;
	n.m3 = 4034953344;
	ret = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (42)
	{
		v = *str;
		n.binlen = binlen(v);
		if (v == 0)
			break;
		if (n.binlen <= 7)
		{
			ret += 1;
			if (ret > prec && prec != -1)
				break;
			octet = *str;
			write(1, &octet, 1);
		}
		else if (n.binlen <= 11)
		{
			ret += 2;
			if (ret > prec && prec != -1)
				break;
			n.c1 = (v << 26) >> 26;
			n.c0 = ((v >>6) << 27) >> 27;

			octet = (n.m1 >> 8) | n.c0;
			write(1, &octet, 1);
			octet = ((n.m1 << 24) >> 24) | n.c1;
			write(1, &octet, 1);
		}

		else if (n.binlen <= 16)
		{
			ret += 3;
			if (ret > prec && prec != -1)
				break;
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
		else
		{
			ret += 4;
			if (ret > prec && prec != -1)
				break;
			n.c3 = (v << 26) >> 26;
			n.c2 = ((v >> 6) << 26) >> 26;
			n.c1 = ((v >> 12) << 26) >> 26;
			n.c0 = ((v >> 18 ) << 29) >> 29;

			octet = (n.m3 >> 24) | n.c0;
			write(1, &octet, 1);
			octet = ((n.m3 << 8) >> 24) | n.c1;
			write(1, &octet, 1);
			octet = ((n.m3 << 16) >> 24) | n.c2;
			write(1, &octet, 1);
			octet = ((n.m3 << 24) >> 24) | n.c3;
			write(1, &octet, 1);
		}
		if (!*++str)
			break;
	}
	return (ret);
}

int	ft_putwidechar(wchar_t *chr)
{	
	int	ret;
	t_mask	n;
	unsigned int v;
	unsigned char octet;

	n.m0 = 0;
	n.m1 = 49280;
	n.m2 = 14712960;
	n.m3 = 4034953344;
	while (42)
	{
		v = *chr;
		n.binlen = binlen(v);
		if (n.binlen <= 7)
		{
			octet = *chr;
			write(1, &octet, 1);
			ret = 1;
		}
		else if (n.binlen <= 11)
		{
			n.c1 = (v << 26) >> 26;
			n.c0 = ((v >>6) << 27) >> 27;

			octet = (n.m1 >> 8) | n.c0;
			write(1, &octet, 1);
			octet = ((n.m1 << 24) >> 24) | n.c1;
			write(1, &octet, 1);
			ret = 2;
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
			ret = 3;
		}
		else
		{
			n.c3 = (v << 26) >> 26;
			n.c2 = ((v >> 6) << 26) >> 26;
			n.c1 = ((v >> 12) << 26) >> 26;
			n.c0 = ((v >> 18 ) << 29) >> 29;

			octet = (n.m3 >> 24) | n.c0;
			write(1, &octet, 1);
			octet = ((n.m3 << 8) >> 24) | n.c1;
			write(1, &octet, 1);
			octet = ((n.m3 << 16) >> 24) | n.c2;
			write(1, &octet, 1);
			octet = ((n.m3 << 24) >> 24) | n.c3;
			write(1, &octet, 1);
			ret = 4;
		}
		break;
	}
	return (ret);
}
