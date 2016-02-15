/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 16:35:21 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;

	ret = 0;
	if (!iscon(d->type))
	{
		ft_putchar(d->type);
		ret++;
		ret = ft_print_nocon(info, ret);
	}
	if (d->type == 'i' || d->type == 'd')
	{
		if (info->type == 1)
		{
			var->c = va_arg(*current, int);
			ret = ft_putcharspec((char)(var->ld), &(d->string));
			ret = print_char(info, d, ret);
		}
	/*	else if (info->type == 2)
		{
			var->h = va_arg(*current, int);
			ret = ft_putl(var->ld, &(d->string));
			ret = print_short(info, d, ret);
		}*/
		else if (info->type == 3)
		{
			var->ld = va_arg(*current,long);
			ret = ft_putl(var->ld, &(d->string));
			ret = print_long(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->ld = va_arg(*current,long long);
			ret = ft_putll(var->lld, &(d->string));
			ret = print_long(info, d, ret);
		}
		else
		{
			var->ld = va_arg(*current,int);
			ret = ft_putll(var->d, &(d->string));
			ret = print_int(info, d, ret);
		}
	}
	if (d->type == 's')
	{
		var->s = va_arg(*current, char *);
		if (var->s)
		{
			ft_putstr(var->s);
		d->retplusreal += ft_strlen(var->s);
		}
		else
			ft_putstr("(null)");
	}
	if (d->type == 'S' || (d->type == 's' && (info->type == 3 || info->type == 4)))
		var->ws = va_arg(*current, wchar_t *);
	if (d->type == 'x')
	{
		var->x = va_arg(*current, unsigned int);
		ret = ft_print_hex(var->x, 0);
	}
	if (d->type == 'X')
	{
		var->x = va_arg(*current, unsigned int);
		ret = ft_print_hex(var->x, 1);
	}
	if (d->type == 'o')
	{
		var->o = va_arg(*current, unsigned int);
		ret = ft_print_oct(var->o);
	}
	if (d->type == 'p')
	{
		var->p = va_arg(*current, void *);
		ft_putstr("0x");
		ret += 2;
		ret += ft_print_hex((long long unsigned)var->p, 0);
	}
	return (ret);
}
