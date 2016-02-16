/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/16 16:45:48 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int test2;
	int test;
	char w;

	w = 'd';
	test = printf("%D\n",-2147483647);
	test2 = ft_printf("%D\n",-2147483647);
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("%24.44d si%1dmpletring%d, fi%drst in line\n", 7, 4242424, 12345, 12121);
	ft_putchar('\n');
	ft_putchar('\n');
	test2 = ft_printf("%24.44d si%1dmpletring%d, fi%drst in line\n", 7, 4242424, 12345, 12121);
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	return (0);
}
