/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 13:32:48 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int test2;
	int test;

	test = printf("%s not my printf : %10.5d simple string, first in line\\n\n","This works well", 42);
	test2 = ft_printf("%s yes my printf : %10.5d simple string, first in line\\n\n","this works well", 42);
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	return (0);
}
