/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:49:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 18:32:49 by guiricha         ###   ########.fr       */
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
	f = "test_string_for_dummies%42.132423431-44s_and_a_bit_h%42   4242.sarder_now%42.11-44s_normall%424vy.";
	while (42)
	{
		if (!(reinit_form(&current)))
			return (-1);
		ret += read_until(f + ret, result);
		retbck = ret + 1;
		ret += modify_form(current, f + ret);
		ret++; // use conversion here before increasing RET!!
		if (current->percent == 1)
			ft_putchar('%');
		if (ret == retbck && (current->percent == -1))
			break;
		//ft_putstr("\n\n");
//		print_form(current);
//		ft_putstr("\n\n");
		
	}
	return (ret);
}
