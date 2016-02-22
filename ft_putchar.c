/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:41:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/22 15:14:47 by guiricha         ###   ########.fr       */
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
	int len;
	int ret;
	int zeroes;
	char *str;

	len = 1;
	zeroes = ft_det_zeroes(len, info, 2);
	str = (char *)malloc(sizeof(char) * (len + zeroes + 1));
	str[len + zeroes] = '\0';
	ret = zeroes;
	while (zeroes--)
		str[zeroes] = '0';
	str[ret] = c;
	*into = str;
	return (ret + len);
}


int		ft_putstrstr(char *input, char **into, t_form *info)
{
	int len;
	int ret;
	int zeroes;
	int n;
	char *str;

	n = 0;
	if (input)
		len = ft_strlen(input);
	else
	{
		input = (char *)malloc(sizeof(char) * (6 + 1));
		input = "(null)\0";
		len = 6;
	}
	if (info->prec != -1)
		len = (info->prec < len ? info->prec : len);
	zeroes = ft_det_zeroes(len, info, 2);
	str = (char *)malloc(sizeof(char) * (len + zeroes + 1));
	str[len + zeroes] = '\0';
	ret = zeroes;
	while (zeroes--)
		str[zeroes] = '0';
	zeroes = len;
	while(len--)
	{
		str[n++ + ret] = *input++;
	}
	*into = str;
	return (ret + zeroes);
}
