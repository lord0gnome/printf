/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/11 14:08:43 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	do_va_crap(va_list *current, char type, t_type *var)
{
	if (type == 'i' || type == 'd')
	{
		var->d = va_arg(*current, int);
		ft_putnbr(var->d);
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
			do_va_crap(ap, format[d.ret], &var);
			d.nargs--;
		}
			d.ret++;
		//todo
		if (current->percent == 1)
		{
			ft_putchar('%');
		}
		//ft_putstr("\n\n");
		//ft_putstr("\n\n");
	}
	return (d.ret);
}
