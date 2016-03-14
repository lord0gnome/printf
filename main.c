/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 17:47:57 by guiricha         ###   ########.fr       */
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
	setlocale(LC_ALL, "");
	test = printf("{%.p, %.0p}\n", 0, 0);
	test2 = ft_printf("{%.p, %.0p}\n", 0, 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("{%.p}\n", 0);
	test2 = ft_printf("{%.p}\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("{%.0p}\n", 0);
	test2 = ft_printf("{%.0p}\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("{%30S}\n", L"我是一只猫。");
	test2 = ft_printf("{%30S}\n", L"我是一只猫。");
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("{%C}\n", 0);
	test2 = ft_printf("{%C}\n", 0);
	test = printf("{%C}\n", 230);
	test2 = ft_printf("{%C}\n", 230);
	test = printf("{%C}\n", 270);
	test2 = ft_printf("{%C}\n", 270);
	test = printf("{%C}\n", 324);
	test2 = ft_printf("{%C}\n", 324);
	test = printf("{%C}\n", 424);
	test2 = ft_printf("{%C}\n", 424);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	return (0);
}
