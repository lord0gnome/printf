/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:36:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 17:55:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	calc_prec_left(t_form *info, t_data *d, int ret, int newret)
{
	while (info->prec - ret > 0)
	{
		ft_putcharprntf('0');
		if (info->width > 0)
			info->width--;
		if (info->prec > 0)
			info->prec--;
		newret++;
	}
	if (*d->string == '0' && d->bck == 0)
		newret--;
	else
		ft_putstr(d->string + info->nega);
	return (newret);
}

int	calc_width_left(t_form *info, int ret, int newret)
{
	while (info->width - ret > 0)
	{
		ft_putcharprntf(' ');
		info->width--;
		newret++;
	}
	return (newret);
}

int	calc_prec_norm(t_form *info, t_data *d, int ret, int newret)
{
	while (info->prec - (ret) > 0)
	{
		newret++;
		ft_putcharprntf('0');
		info->prec--;
	}
	if (d->string[info->nega] == '0' && d->bck == 0 + (info->force * 2))
		newret--;
	else
	{
		if (d->string)
			ft_putstr(d->string + info->nega);
		info->force = 0;
	}
	return (newret);
}

int	calc_width_norm(t_form *info, t_data *d, int ret, int newret)
{
	while (info->width - (info->prec - ret) - ret > 0)
	{
		info->width--;
		newret++;
		ft_putcharprntf(d->ospace);
	}
	return (newret);
}

int	print_unsigned(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	d->bck = info->prec;
	d->ospace = info->zero == 1 && info->prec < 0 ? '0' : ' ';
	if (info->prec == -1 || (info->prec < ret && info->prec != 0))
		info->prec = ret;
	if (info->width == -1)
		info->width = 0;
	if (!info->left)
	{
		if (info->width > ret && info->zero)
			decide_force(info, d);
		newret = calc_width_norm(info, d, ret, newret);
		decide_force(info, d);
		newret = calc_prec_norm(info, d, ret, newret);
	}
	else
	{
		decide_force(info, d);
		newret = calc_prec_left(info, d, ret, newret);
		newret = calc_width_left(info, ret, newret);
	}
	d->tmp = 0;
	return (newret + ret);
}
