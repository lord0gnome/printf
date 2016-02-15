/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:33:39 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 12:43:57 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info)
{
	int ret;

	ret = 0;
	if (d->type == 'i' || d->type == 'd')
	{
		if (info->type == 3)
		{
			var->ld = va_arg(*current,long);
			
			ret = ft_putll(var->ld, &(d->string));
		}
		else if (info->type == 4)
		{
			var->ld = va_arg(*current,long long);
			ret = ft_putll(var->lld, &(d->string));
		}
		else
		{
			var->ld = va_arg(*current,int);
			ret = ft_putll(var->d, &(d->string));
			if (info->left == 0)
			{
				while (info->width - ret)
				{
					if (info->width - info->prec  > 0)
					{
						ft_putchar(' ');
					}
					else
						ft_putchar('0');
					d->retplusreal++;
					info->width--;
				}
				ft_putstr(d->string);
			}
			else if (info->left == 1)
			{
					while (info->prec - ret > 0)
					{
						ft_putchar('0');
						info->prec--;
					}
				ft_putstr(d->string);
				while (info->width - ret)
				{
					ft_putchar(' ');
					d->retplusreal++;
					info->width--;
				}
			}
		}
	}
	if (d->type == 's')
	{
		var->s = va_arg(*current, char *);
		ft_putstr(var->s);
		d->retplusreal += ft_strlen(var->s);
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
	return (ret);
}
