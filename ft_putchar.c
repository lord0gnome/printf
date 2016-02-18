/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:41:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 15:17:22 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putcharstr(char c, char **into)
{
	int	t;

	t = 0;
	if (c)
	{
		*into = (char *)malloc(sizeof(char));
		**into = c;
		return (1);
	}
	else
	{
		*into = "\0";
		return (1);
	}
}
