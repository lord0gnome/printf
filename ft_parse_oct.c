/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:10:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 13:10:42 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_parse_oct(unsigned long long n)
{
	long long	bck;
	char		*octstr;
	int			len;
	int			lenret;

	bck = n;
	len = 1;
	if (n == 0)
		ft_putstr("0\0");
	while (bck /= 8)
		len++;
	octstr = (char *)malloc(sizeof(char) * len + 1);
	octstr[len] = '\0';
	lenret = len;
	while (n)
	{
		len--;
		octstr[len] = (n % 8) + (48);
		n /= 8;
	}
	ft_putstr(octstr);
	return (lenret);
}
