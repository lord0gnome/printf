/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/03 14:40:12 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;
	char xorX;

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
			ret = ft_strlen(d->string = ft_itoabase((var->c), 10, 0));
			ret = print_long(info, d, ret);
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
			ret = print_long(info, d, ret);
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
			var->lld = (long long)va_arg(*current, size_t);
			ret = ft_strlen(d->string = ft_itoabase((var->lld), 10, 0));
			ret = print_long(info, d, ret);
		}
	}
	if (d->type == 'c')
	{
		var->c = (char)va_arg(*current, int);
		ret = ft_putcharstr(var->c, &(d->string), info);
		ret = print_char(info, d, ret);
	}
	/*	if (d->type == 'C')
		{
		var->wc = (wchar_t)va_arg(*current, int)
		ret = ft_putwidechar(var->wc);
		}*/
	if (d->type == 's')
	{
		var->s = va_arg(*current, char *);
		ret = ft_putstrstr(var->s, &(d->string), info);
		ret = print_str(info, d, ret);
	}
	/*if (d->type == 'S' || (d->type == 's' && (info->type == 3 || info->type == 4)))
	  var->wc = va_arg(*current, wchar_t *);*/
	if (d->type == 'x' || d->type == 'X')
	{
		info->bigsmall = d->type;
		xorX = d->type == 'x' ? 0 : 1;
		if (info->prec != -1 && info->force == 1 && info->prec != 0)
			info->prec += 2;
		if (info->type == 3)
		{
			var->O = va_arg(*current, long unsigned);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->O), 16, xorX));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->llu = va_arg(*current, long long unsigned);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->llu), 16, xorX));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 2)
		{
			var->hh = (unsigned char)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->hh), 16, xorX));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->uh = (unsigned short)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->uh), 16, xorX));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 0)
		{
			var->x = va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->x), 16, xorX));
			ret = print_longu(info, d, ret);
		}
	}
	if (d->type == 'o' || d->type == 'O')
	{
		if (d->type == 'O')
			info->type = 3;
		if (info->type == 0)
		{
			var->o = va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseo(info,(var->o), 8));
			ret = print_longu(info, d, ret);
		}
		if (info->type == 2)
		{
			var->hh = (unsigned char)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->hh), 8));
			ret = print_longu(info, d, ret);
		}
		if (info->type == 1)
		{
			var->uh = (unsigned short)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->uh), 8));
			ret = print_longu(info, d, ret);
		}
		if (info->type == 3)
		{
			var->O = (unsigned long int)va_arg(*current, unsigned long int);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->O), 8));
			ret = print_longu(info, d, ret);
		}
		if (info->type == 4)
		{
			var->llu = (unsigned long long)va_arg(*current, unsigned long long);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->llu), 8));
			ret = print_longu(info, d, ret);
		}
	}
	if (d->type == 'p')
	{
		var->z = (size_t)va_arg(*current, size_t);
		info->force = 1;
		xorX = 0;
		if (info->prec != -1)
			info->prec += 2;
		ret = ft_strlen(d->string = ft_itoabasep(info ,(var->z), 16, xorX));
		ret = print_longu(info, d, ret);
	}
	if (d->type == 'u')
	{
		if (info->type == 0)
		{
			var->x = (unsigned int)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseu((var->x), 10, 0));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 2)
		{
			var->hh = (unsigned char)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseu((var->hh), 10, 0));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->uh = (unsigned short)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabaseu((var->uh), 10, 0));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 3)
		{
			var->O = (long unsigned int)va_arg(*current, unsigned long int);
			ret = ft_strlen(d->string = ft_itoabaseu((var->O), 10, 0));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->llu = va_arg(*current, unsigned long long int);
			ret = ft_strlen(d->string = ft_itoabaseu((var->llu), 10, 0));
			ret = print_longu(info, d, ret);
		}
	}
	if (d->type == 'U')
	{
		var->O = (long unsigned int)va_arg(*current, long unsigned int);
		ret = ft_strlen(d->string = ft_itoabaseu((var->O), 10, 0));
		ret = print_long(info, d, ret);
	}

	return (ret);
}
