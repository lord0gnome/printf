/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_store.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:31:19 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 18:31:48 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	modify_form(t_form *c, const char *restrict f)
{
	int		i;
	int		bck;

	i = 0;
	while (isvalid(f[i]) && f[i])
	{
		if (f[i] == '.' && !isvalid(f[i + 1]))
			c->prec = 0;
		if (isnum(f[i]) && f[i] != '0')
		{
			if (f[i - 1] == '.')
			{
				bck = c->prec;
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
			continue ;
		}
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
		i++;
	}
	return (i);
}
