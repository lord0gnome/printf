/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/18 16:23:26 by guiricha         ###   ########.fr       */
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
	test = printf("'%zi'\n", -48);
	test2 = ft_printf("'%zi'\n", -48);
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("longd:'%10.9D'\n", 1);
	test2 = ft_printf("longd:'%10.9D'\n", 1);
	test = printf("hex  :'%10.9x'\n", 1);
	test2 = ft_printf("hex  :'%10.9x'\n", 1);
	test = printf("hexcp:'%10.9X'\n", 100000);
	test2 = ft_printf("hexcp:'%10.9X'\n", 100000);
	test = printf("pntr :'%10.9p'\n", 1);
	test2 = ft_printf("pntr :'%10.9p'\n", 1);
	test = printf("nsngd:'%10.9u'\n", 1);
	test2 = ft_printf("nsngd:'%10.9u'\n", 1);
	test = printf("strng:'%10.9s'\n", "42");
	test2 = ft_printf("strng:'%10.9s'\n", "42");
	test = printf("tcchar :'[%3c]'\n", 0);
	test2 = ft_printf("mcchar :'[%3c]'\n", 0);
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_putchar('\n');
	return (0);
}
