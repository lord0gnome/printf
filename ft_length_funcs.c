/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/24 16:01:05 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;
	int x;

	x = (d->type == 'x' ? 0 : 1);
	info->bigsmall = d->type;
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
			ret = ft_strlen(d->string = ft_itoabase((var->d), 10, 0));
			ret = print_char(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->h = (short)va_arg(*current, int);
			ret = ft_strlen(d->string = ft_itoabase((var->h), 10, 0));
			ret = print_long(info, d, ret);
		}
		else if (info->type == 3)
		{
			var->ld = va_arg(*current,long);
			ret = ft_strlen(d->string = ft_itoabase((var->ld), 10, 0));
			ret = print_int(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->lld = va_arg(*current,long long);
			ret = ft_strlen(d->string = ft_itoabase((var->lld), 10, 0));
			ret = print_long(info, d, ret);
		}
		else if (info->type == 0)
		{
			var->d = (int)va_arg(*current, int);
			ret = ft_strlen(d->string = ft_itoabase((var->d), 10, 0));
			ret = print_long(info, d, ret);
		}
		else if (info->type == 6)
		{
			var->llu = (unsigned long long)va_arg(*current, size_t);
			ret = ft_putll(var->llu, &(d->string), info);
			ret = print_int(info, d, ret);
		}
	}
	if (d->type == 'c')
	{
		var->c = (char)va_arg(*current, int);
		ret = ft_putcharstr(var->c, &(d->string), info);
		ret = print_char(info, d, ret);
	}
	if (d->type == 's')
	{
		var->s = va_arg(*current, char *);
		ret = ft_putstrstr(var->s, &(d->string), info);
		ret = print_str(info, d, ret);
	}
	if (d->type == 'S' || (d->type == 's' && (info->type == 3 || info->type == 4)))
		var->ws = va_arg(*current, wchar_t *);
	if (d->type == 'x' || d->type == 'X')
	{
		if (info->prec != -1 && info->force == 1 && info->prec != 0)
			info->prec += 2;
		if (info->type == 3)
		{
			var->O = va_arg(*current, long unsigned);
			ret = ft_parse_hex(var->O, x, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->llu = va_arg(*current, long long unsigned);
			ret = ft_parse_hex(var->llu, x, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 2)
		{
			var->hh = (unsigned char)va_arg(*current, int);
			ret = ft_parse_hex((var->c), x, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->uh = (unsigned short)va_arg(*current, int);
			ret = ft_parse_hex(var->uh, x, &(d->string), info);
			ret = print_int(info, d, ret);
		}
		else if (info->type == 0)
		{
			var->x = va_arg(*current, unsigned int);
			ret = ft_parse_hex(var->x, x, &(d->string), info);
			ret = print_int(info, d, ret);
		}
	}
	if (d->type == 'o')
	{
		var->o = va_arg(*current, unsigned int);
		ret = ft_parse_oct(var->o, &(d->string), info);
		ret = print_int(info, d, ret);
	}
	if (d->type == 'O' || (d->type == 'o' && info->type == 3))
	{
		var->O = va_arg(*current, unsigned long int);
		ret = ft_parse_oct(var->O, &(d->string), info);
		ret = print_int(info, d, ret);
	}

	if (d->type == 'p')
	{
		var->p = va_arg(*current, void *);
		info->force = 1;
		info->bigsmall = 'x';
		if (info->prec != -1)
			info->prec += 2;
		ret = ft_parse_ptr((long long unsigned)var->p, 0, &(d->string), info);
		ret = print_int(info, d, ret);
	}
	if (d->type == 'u')
	{
		var->x = (unsigned int)va_arg(*current, unsigned int);
		ret = ft_putllu(var->x, &(d->string), info);
		ret = print_int(info, d, ret);
	}

	if (d->type == 'U')
	{
		var->O = (long unsigned int)va_arg(*current, long unsigned int);
		ret = ft_putllu(var->O, &(d->string), info);
		ret = print_int(info, d, ret);
	}

	return (ret);
}
