/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:41:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/19 15:58:11 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putcharstr(char c, char **into, t_form *info)
{
	int	t;
	int len;
	int ret;
	char *str;

	len = 1;
	t = ft_det_zeroes(len, info, 0);
	str = (char *)malloc(sizeof(char) * (t + len + 1));
	str[t + len] = '\0';
	ret = t + len;
	len = t;
	str[ret - 1] = c;
	while (len--)
		str[len] = '0';
	*into = str;
	return (ret);
}
