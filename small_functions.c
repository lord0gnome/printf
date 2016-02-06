/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 10:46:27 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/06 17:27:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_asprintf.h"
#include <stdlib.h>
#include "libft/libft.h"

int	get_next_percent(const char *restrict format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	if (!format[i])
		return (-1);
	return (i);
}

int	reinit_form(t_form **form)
{
	if (!(*form = (t_form *)malloc(sizeof(t_form))))
		return (-1);
	(*form)->prec = -1;
	(*form)->width = -1;
	(*form)->left = 0;
	(*form)->zero = 0;
	(*form)->space = 0;
	(*form)->plus = 0;
	(*form)->force = 0;
	return (1);
}

int	isnum(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int	check_prec(const char *restrict format)
{
	int	i;

	i = 1;
	if (format[i] && !isnum(format[i]))
		return (0);
	if (format[i] && isnum(format[i]))
		return (ft_atoi(format + i));
	return (-1);
}

int	isvalid(char c)
{
	if (!isnum(c) && c != ' ' && c != '+' && c != '-' && c != '.' && c != '#'
				  && c != 'l' && c != 'h' && c != 'z' && c != '%')
		return (0);
	else
		return (1);
}
