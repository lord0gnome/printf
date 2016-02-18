/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 16:17:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *restrict format, ...)
{
	char	*result;
	t_form *current;
	t_data *d;
	va_list ap;
	t_type	var;

	if (!(reinit_form(&current)))
		return (-1);
	if (!(init_data(&d)))
		return (-1);
	va_start(ap, format);
	result = NULL;
	while ((d->ib != d->i || current->percent != -1) && format[d->i] && d->i < (int)ft_strlen(format))
	{
		if (!(reinit_form(&current)))
			return (-1);
		d->i += read_until(format + d->i, result, d);
		d->ib = d->i;
		d->i += modify_form(current, format + d->i, d);
		d->type = format[d->i];
		d->string = NULL;
		if (d->nargs > 0)
		{
			d->retplusreal += do_va_crap(&ap, d, &var, current);
			d->nargs--;
			d->i++;
		}
		//todo
		//ft_putstr("\n\n");
//		print_form(current);
		//ft_putstr("\n\n");
	}
	return (d->retplusreal);
}
