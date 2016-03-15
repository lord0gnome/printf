/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/15 11:49:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	do_va(va_list *now, t_data *d, t_type *var, t_form *i)
{
	int ret;

	ret = 0;
	if (!iscon(d->type))
	{
		if (i->left == 1 && (!(isvalid(d->type)) || d->type == '%'))
			ft_putchar(d->type);
		if ((!(isvalid(d->type)) || d->type == '%'))
			ret++;
		ret = print_nocon(i, ret);
		if (i->left == 0 && (!(isvalid(d->type)) || d->type == '%'))
			ft_putchar(d->type);
	}
	else if (d->type == 'c' && i->type != 3)
	{
		var->c = (char)va_arg(*now, int);
		ret = ft_putcharstr(var->c, &(d->string), i);
		ret = print_char(i, d, ret);
		free(d->string);
	}
	else if (d->type == 's' && i->type != 3)
	{
		var->s = va_arg(*now, char *);
		ret = ft_strlen(d->string = ft_putstrstr(var->s, i));
		ret = print_str(i, d, ret);
		free(d->string);
	}
	return (ret);
}

int			do_va(va_list *now, t_data *d, t_type *var, t_form *i)
{
	int ret;
	char x;

	i->bigsmall = d->type;
	ret = 0;
	ret = 
	/*if (!iscon(d->type))
	{
		if (i->left == 1 && (!(isvalid(d->type)) || d->type == '%'))
			ft_putchar(d->type);
		if ((!(isvalid(d->type)) || d->type == '%'))
			ret++;
		ret = print_nocon(i, ret);
		if (i->left == 0 && (!(isvalid(d->type)) || d->type == '%'))
			ft_putchar(d->type);
	}
	else if (d->type == 'c' && i->type != 3)
	{
		var->c = (char)va_arg(*now, int);
		ret = ft_putcharstr(var->c, &(d->string), i);
		ret = print_char(i, d, ret);
		free(d->string);
	}
	else if (d->type == 's' && i->type != 3)
	{
		var->s = va_arg(*now, char *);
		ret = ft_strlen(d->string = ft_putstrstr(var->s, i));
		ret = print_str(i, d, ret);
		free(d->string);
	}*/
	if (d->type == 'i' || d->type == 'd' || d->type == 'D')
		ret = han_int(now, d, var, i);
	else if (d->type == 'x' || d->type == 'X')
	{
		i->bigsmall = d->type;
		if (i->prec != -1 && i->force == 1 && i->prec != 0)
			i->prec += 2;
		ret = han_hex(now, d, var, i);	
	}
	else if (d->type == 'o' || d->type == 'O')
		ret = han_oct(now, d, var, i);
	else if (d->type == 'p')
	{
		var->z = (size_t)va_arg(*now, size_t);
		i->force = 1;
		x = 0;
		if (i->prec != -1)
			i->prec += 2;
		ret = ft_strlen(d->string = itoabasep(i ,(var->z), 16, x));
		ret = print_unsigned(i, d, ret);
		free(d->string);
	}
	else if (d->type == 'u' || d->type == 'U')
		ret = han_nsg(now, d, var, i);
	else if ((d->type == 'c' && i->type == 3) || d->type == 'C')
	{
		var->wc = (wchar_t)va_arg(*now, wchar_t);
		i->type = 'C';
		i->prec = -1;
		ret = get_wstrlen(&var->wc, i);
		print_wstr(i, ret, &var->wc);
	}
	else if ((d->type == 's' && i->type == 3) || d->type == 'S')
	{
		var->ws = (wchar_t *)va_arg(*now, wchar_t *);
		ret = get_wstrlen(var->ws, i);
		ret = print_wstr(i, ret, var->ws);
	}
	return (ret);
}
