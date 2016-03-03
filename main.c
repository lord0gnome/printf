/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/03 14:39:36 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int test2;
	int test;

	test =     printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	test2 = ft_printf("%052.32d How aa%.6sbbb%#23.10occcc%24.42mxed ca%on I make this\n", 42, "a longer string than 6", 420, 402);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("wizards'%#.3o'\n", 1);
	test2 = ft_printf("wizards'%#.3o'\n", 1);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("'%hhx'\n", UCHAR_MAX);
	test2 = ft_printf("'%hhx'\n", UCHAR_MAX);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_printf("%lu, %lu\n", sizeof(int), sizeof(long));
	printf("%lu, %lu\n", sizeof(int), sizeof(long));
	test = printf("tlongd:'%10d'\n", -42);
	test2 = ft_printf("mlongd:'%10d'\n", -42);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("hex  :'%#08X'\n", 99999994);
	test2 = ft_printf("hex  :'%#08X'\n", 99999994);
	test = printf("hexcp:'%#o'\n", 0);
	test2 = ft_printf("hexcp:'%#o'\n", 0);
	test = printf("nsngd:'%p'\n", 0);
	test2 = ft_printf("nsngd:'%p'\n", 0);
	test = printf("strngtwo:'%.p'\n", 0);
	test2 = ft_printf("strngotw:'%.p'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("strng:'%#.5x'\n", 1);
	test2 = ft_printf("strng:'%#.5x'\n", 1);
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
