/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_store.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 17:17:52 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modify_form(t_form *c, const char *restrict f)
{
	int		i;
	int		bck;

	i = 0;
	i++;
	while (isvalid(f[i]))
	{
		if (f[i] == '%')
		{
			c->percent = 1;
			return (i + 1);
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
		if (f[i] == '0' && !c->left && (f[i - 1] == '%' || !isnum(f[i - 1])))
			c->zero = 1;
		if (f[i] == '#')
			c->force = 1;
		if (isnum(f[i]) && f[i] != '0')
		{
			if (f[i - 1] == '.')
			{
				c->prec = check_prec(f + i);
				if (c->prec != 0 && c->prec != -1)
					while (isnum(f[i]))
						i++;
			}
			else
			{
				bck = c->width;
				c->width = ft_atoi(f + i);
				if (c->width == 0)
					c->width = bck;
				if (c->width != -1 && c->width != bck)
					while(isnum(f[i]))
						i++;
			}
		}
		i++;
	}
	return (i - 1);
}
