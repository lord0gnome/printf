/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_store.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/20 17:35:40 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_width_nd_prec(t_form *c, const char *restrict f, int i)
{
	if (f[i] == '.' && (!isvalid(f[i + 1]) || f[i + 1] == '0'))
	{
		c->prec = 0;
		return (i + 1);
	}
	if (isnum(f[i]) && f[i] != 0)
	{
		if (f[i - 1] == '.')
		{
			c->prec = check_prec(f + i);
			while (isnum(f[i]))
				i++;
		}
		else
		{
			c->width = ft_atoi(f + i);
			while(isnum(f[i]))
				i++;
		}
	}
	return (i);
}

int	modify_form(t_form *c, const char *restrict f, t_data *d)
{
	int		i;

	i = 0;
	if (f[i] == '%' && f[i + 1])
		i++;
	else
		return (0);
	while (isvalid(f[i]) && f[i])
	{
		if (f[i] == '.' && (!isvalid(f[i + 1]) || f[i + 1] == '0'))
			c->prec = 0;
		if (isnum(f[i]) && f[i] != '0')
		{
			i = get_width_nd_prec(c, f, i);
			continue ;
		}
		if (f[i] == '%')
		{
			d->nargs++;
			c->percent = 1;
			return (i);
		}
		if (f[i] == '+')
		{
			c->plus = 1;
			c->space = 0;
		}
		if (f[i] == ' ' && !c->plus)
			c->space = 1;
		if (f[i] == '-')
		{
			c->left = 1;
			c->zero = 0;
		}
		if (f[i] == '0' && f[i - 1] != '.' && !c->left && (f[i - 1] == '%' || (!isnum(f[i - 1])) || ((isnum(f[i - 1]) && f[i - 1] == '0'))))
			c->zero = 1;
		if (f[i] == '#')
			c->force = 1;
		if (f[i] == 'h')
		{
			if (c->type != 1 && c->type != 2)
				c->type = 1;
			else if (c->type == 1)
				c->type = 2;
			else if (c->type == 2)
				c->type = 1;
		}
		if (f[i] == 'l')
		{
			if (c->type != 3 && c->type != 4)
				c->type = 3;
			else if (c->type == 3)
				c->type = 4;
			else if (c->type == 4)
				c->type = 3;
		}
		if (f[i] == 'j')
			c->type = 5;
		if (f[i] == 'z')
			c->type = 6;
		if (f[i] == 'L')
			c->type = 7;
		i++;
	}
	d->nargs++;
	return (i);
}
