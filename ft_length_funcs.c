/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/07 16:17:36 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	doallints2(va_list *current, t_data *d, t_type *var, t_form *info)
{
	if (info->type == 3)
	{
		var->ld = va_arg(*current,long);
		d->string = ft_itoabase((var->ld), 10, 0);
	}
	if (info->type == 4)
	{
		var->lld = va_arg(*current,long long);
		d->string = ft_itoabase((var->lld), 10, 0);
	}
	else if (info->type == 5)
	{
		var->im = (intmax_t)va_arg(*current, intmax_t);
		d->string = ft_itoabase((var->im), 10, 0);
	}
	else if (info->type == 6)
	{
		var->lld = (long long)va_arg(*current, size_t);
		d->string = ft_itoabase((var->lld), 10, 0);
	}
}

int		doallints1(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;

	ret = 0;
	if (d->type == 'D')
		info->type = 3;
	if (info->type == 2)
	{
		var->c = (char)va_arg(*current, int);
		d->string = ft_itoabase((var->c), 10, 0);
	}
	else if (info->type == 1)
	{
		var->h = (short)va_arg(*current, int);
		d->string = ft_itoabase((var->h), 10, 0);
	}
	else if (info->type == 0)
	{
		var->d = (int)va_arg(*current, int);
		d->string = ft_itoabase((var->d), 10, 0);
	}
	doallints2(current, d, var, info);
	ret = ft_strlen(d->string);
	ret = print_long(info, d, ret);
	return (ret);
}


int		do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;
	char x;

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
	else if (d->type == 'i' || d->type == 'd' || d->type == 'D')
		ret = doallints1(current, d, var, info);
	if (d->type == 'c' && info->type != 3)
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
	if (d->type == 's' && info->type != 3)
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
		x = d->type == 'x' ? 0 : 1;
		if (info->prec != -1 && info->force == 1 && info->prec != 0)
			info->prec += 2;
		if (info->type == 3)
		{
			var->O = va_arg(*current, long unsigned);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->O), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 4)
		{
			var->llu = va_arg(*current, long long unsigned);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->llu), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 2)
		{
			var->hh = (unsigned char)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->hh), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 1)
		{
			var->uh = (unsigned short)va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->uh), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 0)
		{
			var->x = va_arg(*current, unsigned int);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->x), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 5)
		{
			var->uim = (uintmax_t)va_arg(*current, uintmax_t);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->uim), 16, x));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 6)
		{
			var->uim = (uintmax_t)va_arg(*current, uintmax_t);
			ret = ft_strlen(d->string = ft_itoabasex(info ,(var->uim), 16, x));
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
		if (info->type == 5)
		{
			var->uim = (uintmax_t)va_arg(*current, uintmax_t);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->uim), 8));
			ret = print_longu(info, d, ret);
		}
		if (info->type == 6)
		{
			var->uim = (uintmax_t)va_arg(*current, uintmax_t);
			ret = ft_strlen(d->string = ft_itoabaseo(info, (var->uim), 8));
			ret = print_longu(info, d, ret);
		}
	}
	if (d->type == 'p')
	{
		var->z = (size_t)va_arg(*current, size_t);
		info->force = 1;
		x = 0;
		if (info->prec != -1)
			info->prec += 2;
		ret = ft_strlen(d->string = ft_itoabasep(info ,(var->z), 16, x));
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
		else if (info->type == 5)
		{
			var->uim = va_arg(*current,uintmax_t);
			ret = ft_strlen(d->string = ft_itoabaseu((var->uim), 10, 0));
			ret = print_longu(info, d, ret);
		}
		else if (info->type == 6)
		{
			var->uim = va_arg(*current,uintmax_t);
			ret = ft_strlen(d->string = ft_itoabaseu((var->uim), 10, 0));
			ret = print_longu(info, d, ret);
		}
	}
	if (d->type == 'U')
	{
		var->O = (long unsigned int)va_arg(*current, long unsigned int);
		ret = ft_strlen(d->string = ft_itoabaseu((var->O), 10, 0));
		ret = print_long(info, d, ret);
	}
	if ((d->type == 'c' && info->type == 3) || d->type == 'C')
	{
		var->wc = (wchar_t)va_arg(*current, wchar_t);
		ret = ft_putwidechar(&var->wc);
	}
	if ((d->type == 's' && info->type == 3) || d->type == 'S')
	{
		var->ws = (wchar_t *)va_arg(*current, wchar_t *);
		ret = get_wstrlen(var->ws, info->prec);
		ret = print_wstr(info, ret, var->ws);
	}

	return (ret);
}
