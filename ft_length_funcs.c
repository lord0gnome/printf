/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/13 17:24:51 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	do_va_crap(va_list *current, char type, t_type *var, t_form *info)
{
	if (type == 'i' || type == 'd')
	{
		if (info->type == 3)
		{
			var->ld = va_arg(*current,long);
			ft_putll(var->ld);
		}
		else if (info->type == 4)
		{
			var->ld = va_arg(*current,long long);
			ft_putll(var->lld);
		}
		else
		{
			var->ld = va_arg(*current,int);
			ft_putnbr(var->d);
		}
	}
	if (type == 's')
	{
		var->s = va_arg(*current, char *);
		ft_putstr(var->s);
	}
	if (type == 'S' || (type == 's' && info->type == 3 || info->type == 4))
		var->ws = va_arg(*current, wchar_t *);
	if (type == 'x')
	{
		var->x = va_arg(*current, unsigned int);
		ft_print_hex(var->x, 0);
	}
	if (type == 'X')
	{
		var->x = va_arg(*current, unsigned int);
		ft_print_hex(var->x, 1);
	}
}
