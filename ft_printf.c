/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/11 13:35:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
/*
   int	do_va_crap(va_list *current, char type, t_type *var)
   {
   if (type == 'i' || type == 'd')
		var.d = va_arg(*current, int);
   if (type == 'c' || type == 'H')

   if (type == 'h')

   if (type == 'j')

   if (type == )

   if (type == )

   if (type == )

   if (type == )

   if (type == )

   if (type == )

   if (type == )

   }
*/
int	ft_printf(const char *restrict format, ...)
{
	char	*result;
	t_form *current;
	t_data d;
	va_list ap;
	t_type	var;

	if (!(reinit_form(&current)))
		return (-1);
	va_start(ap, format);
	d.nargs = 0;
	d.ret = 0;
	d.retbck = 42;
	while (d.ret != d.retbck || current->percent != -1)
	{
		if (!(reinit_form(&current)))
			return (-1);
		d.ret += read_until(format + d.ret, result);
		d.retbck = d.ret + 1;
		d.ret += modify_form(current, format + d.ret, &d);
		if (d.nargs > 0)
		{
	
			if (format[d.ret] == 'd')
			{
				var.d = va_arg(ap, int);
				while (current->width > 0)
				{
					ft_putchar('_');
					current->width--;
				}
				ft_putnbr(var.d);
			}

			d.nargs--;
		}
		//todo
		d.ret++; // use conversion here before increasing RET!!
		if (current->percent == 1)
		{
			ft_putchar('%');
		}
		//ft_putstr("\n\n");
		print_form(current);
		//ft_putstr("\n\n");

	}
	return (d.ret);
}
