/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/19 16:13:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
	test = printf("t:'%03 c'\n", 0);
	test2 = ft_printf("m:'%03 c'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("tlongd:'%#5.4x'\n", 1);
	test2 = ft_printf("mlongd:'%#5.4x'\n", 1);
	test = printf("hex  :'%#08X'\n", 4);
	test2 = ft_printf("hex  :'%#08X'\n", 4);
	test = printf("hexcp:'%X'\n", 4294967296);
	test2 = ft_printf("hexcp:'%X'\n", 4294967296);
	test = printf("nsngd:'% u'\n", 9999);
	test2 = ft_printf("nsngd:'% u'\n", 9999);
	test = printf("strng:'%10.1s'\n", "42");
	test2 = ft_printf("strng:'%10.1s'\n", "42");
	test = printf("tcchar :'{%3c}'\n", 0);
	test2 = ft_printf("mcchar :'{%3c}'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	return (0);
}
