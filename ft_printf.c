/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/13 14:25:21 by guiricha         ###   ########.fr       */
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
		}
		else
		{
			var->ld = va_arg(*current,long);
		}
		ft_putll(var->ld);
	}
	if (type == 's')
	{
		var->s = va_arg(*current, char *);
		ft_putstr(var->s);
	}
	//if (type == 'c' || type == 'H')

		/*   if (type == 'h')

			 if (type == 'j')

			 if (type == )

			 if (type == )

			 if (type == )

			 if (type == )

			 if (type == )

			 if (type == )

			 if (type == )*/

}

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
	while ((d.retbck != d.ret || current->percent != -1) && format[d.ret] && d.ret < ft_strlen(format))
	{
		if (!(reinit_form(&current)))
			return (-1);
		d.ret += read_until(format + d.ret, result);
		d.retbck = d.ret;
		d.ret += modify_form(current, format + d.ret, &d);
		if (d.nargs > 0)
		{
			do_va_crap(ap, format[d.ret], &var, current);
			d.nargs--;
		}
			d.ret++;
		//todo
		if (current->percent == 1)
		{
			ft_putchar('%');
		}
		//ft_putstr("\n\n");
	//	print_form(current);
		//ft_putstr("\n\n");
	}
	return (d.ret);
}
