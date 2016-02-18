/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 16:22:06 by guiricha         ###   ########.fr       */
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
		if (info->left == 1)
			ft_putchar(d->type);
		ret++;
		ret = ft_print_nocon(info, ret);
		if (info->left == 0)
			ft_putchar(d->type);
	}
	if (d->type == 'i' || d->type == 'd' || d->type == 'D')
	{
		if (d->type == 'D')
			info->type = 3;
		if (info->type == 2)
		{
			var->c = (char)va_arg(*current, int);
			ret = ft_putll((var->c), &(d->string), info);
			ret = print_char(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->h = (short)va_arg(*current, int);
			ret = ft_putll(var->h, &(d->string), info);
			ret = print_long(info, d, ret);
		}
		else if (info->type == 3)
		{
			var->ld = va_arg(*current,long);
			ret = ft_putll(var->ld, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->ld = va_arg(*current,long long);
			ret = ft_putll(var->lld, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 0)
		{
			var->d = va_arg(*current,int);
			ret = ft_putll(var->d, &(d->string), info);
			ret = print_int(info, d, ret);
		}
	}
	if (d->type == 'c')
	{
		var->c = (char)va_arg(*current, int);
		ret = ft_putcharstr(var->c, &(d->string));
		ret = print_int(info, d, ret);
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
		ret = ft_parse_hex(var->x, 0);
	}
	if (d->type == 'X')
	{
		var->x = va_arg(*current, unsigned int);
		ret = ft_parse_hex(var->x, 1);
	}
	if (d->type == 'o')
	{
		var->o = va_arg(*current, unsigned int);
		ret = ft_parse_oct(var->o);
	}
	if (d->type == 'p')
	{
		var->p = va_arg(*current, void *);
		ft_putstr("0x");
		ret += 2;
		ret += ft_parse_hex((long long unsigned)var->p, 0);
	}
	if (d->type == 'u')
	{
		var->x = (unsigned int)va_arg(*current, unsigned int);
		ret = ft_putll(var->x, &(d->string), info);
		ret = print_int(info, d, ret);
	}
	return (ret);
}
