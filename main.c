/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/07 15:45:46 by guiricha         ###   ########.fr       */
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
test =	printf("'%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S'\n",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
test2 =	ft_printf("'%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S'\n",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("they'%4.15S'\n", L"我是一只猫。");
	test2 = ft_printf("mine'%4.15S'\n", L"我是一只猫。");
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("'%05.S'\n", L"42 cest cool");
	test2 = ft_printf("'%05.S'\n", L"42 cest cool");
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_printf("%lu, %lu\n", INT_MAX, LONG_MAX);
	printf("%lu, %lu\n", INT_MAX, LONG_MAX);
	test = printf("tlongd:'%10d'\n", -42);
	test2 = ft_printf("mlongd:'%#10d'\n", -42);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("hex  :'%#08X'\n", 99999994);
	test2 = ft_printf("hex  :'%#08X'\n", 99999994);
	test = printf("hexcp:'%#o'\n", 0);
	test2 = ft_printf("hexcp:'%#o'\n", 0);
	test = printf("nsngd:'%zx%zx'\n", 0, ULLONG_MAX);
	test2 = ft_printf("nsngd:'%zx%zx'\n", 0, ULLONG_MAX);
	test = printf("strngtwo:'%05p'\n", 0);
	test2 = ft_printf("strngotw:'%05p'\n", 0);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	test = printf("strng:'%#05x'\n", 0);
	test2 = ft_printf("strng:'%#05x'\n", 0);
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
