/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/22 16:14:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int test2;
	int test;
	int	ageofsis;

	ageofsis = 21747;
	test =     printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	test2 = ft_printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("'%08.5s'\n", 0);
	test2 = ft_printf("'%08.5s'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("tlongd:'%#5.4x'\n", 1);
	test2 = ft_printf("mlongd:'%#5.4x'\n", 1);
	test = printf("hex  :'%#08X'\n", 4);
	test2 = ft_printf("hex  :'%#08X'\n", 4);
	test = printf("hexcp:'%D'\n", 0);
	test2 = ft_printf("hexcp:'%D'\n", 0);
	test = printf("nsngd:'% u'\n", 9999);
	test2 = ft_printf("nsngd:'% u'\n", 9999);
	test = printf("strng:'%.0p'\n", 0);
	test2 = ft_printf("strng:'%.0p'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("strng:'%.5p'\n", 0);
	test2 = ft_printf("strng:'%.5p'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("tcchar :'{%3c}'\n", 0);
	test2 = ft_printf("mcchar :'{%3c}'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	return (0);
}
