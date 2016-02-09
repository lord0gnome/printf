/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 17:17:54 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(void)
{
	char	*result;
	const char *restrict f;
	int	ret;
	int retbck;

	t_form *current;
	if (!(reinit_form(&current)))
		return (-1);


	ret = 0;
	retbck = 0;
	f = "test string for dummies.%42.11-44s and a bit h%4242 42 42  4242--+sarder now normally.";
	while (42)
	{
		if (!(reinit_form(&current)))
			return (-1);
		retbck = ret;
		ret += read_until(f + ret, result);
		retbck = ret;
		ret += modify_form(current, f + ret);
		if (current->percent == 1)
			ft_putchar('%');
		if (ret == retbck && (current->percent == -1))
			break;
		//ft_putstr("\n\n");
		print_form(current);
		ft_putstr("\n\n");
		
	}
	return (ret);
}

