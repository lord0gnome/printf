/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/24 16:37:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int test2;
	int test;
	int	ageofsis;
	int	nbr;
	char *str;

	nbr = LONG_MIN;
	str = ft_itoabase(434535, 15, 1);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');


	ageofsis = 21747;
	test =     printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	test2 = ft_printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("wizards'%0.d'\n", 0);
	test2 = ft_printf("wizards'%0.d'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("'%D'\n", 50000000000);
	test2 = ft_printf("'%D'\n", 50000000000);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_printf("%lu, %lu\n", sizeof(int), sizeof(long));
	printf("%lu, %lu\n", sizeof(int), sizeof(long));
	test = printf("tlongd:'%#x'\n", 0);
	test2 = ft_printf("mlongd:'%#x'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("hex  :'%#08X'\n", 99999994);
	test2 = ft_printf("hex  :'%#08X'\n", 99999994);
	test = printf("hexcp:'%#.0o'\n", 0);
	test2 = ft_printf("hexcp:'%#.0o'\n", 0);
	test = printf("nsngd:'% u'\n", 9999);
	test2 = ft_printf("nsngd:'% u'\n", 9999);
	test = printf("strng:'%9.2p'\n", 1234);
	test2 = ft_printf("strng:'%9.2p'\n", 1234);
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
