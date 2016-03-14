/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 13:12:43 by guiricha         ###   ########.fr       */
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
	  test = printf("they'%S'\n", L"我是一我是一只猫。只猫。");
	  test2 = ft_printf("mine'%S'\n", L"我是一我是一只猫。只猫。");
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	  test = printf("'%#6o'\n", 2500);
	  test2 = ft_printf("'%#6o'\n", 2500);
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	  ft_printf("%lu, %lu\n", INT_MAX, LONG_MAX);
	  printf("%lu, %lu\n", INT_MAX, LONG_MAX);
	  test = printf("tlongd:'%10hd'\n", -42);
	  test2 = ft_printf("mlongd:'%10hd'\n", -42);
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	  test = printf("hex  :'%#08X'\n", 99999994);
	  test2 = ft_printf("hex  :'%#08X'\n", 99999994);
	  test = printf("hexcp:'%#u'\n", 0);
	  test2 = ft_printf("hexcp:'%#u'\n", 0);
	  test = printf("nsngd:'%zo%zo'\n", 0, ULLONG_MAX);
	  test2 = ft_printf("nsngd:'%zo%zo'\n", 0, ULLONG_MAX);
	  test = printf("strngtwo:'%05s'\n", "syinrg");
	  test2 = ft_printf("strngotw:'%05s'\n", "syinrg");
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	  test = printf("%zhd\n", UINT_MAX);
	  test2 = ft_printf("%zhd\n", UINT_MAX);
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	  test = printf("strng:'%.0d'\n", 0);
	  test2 = ft_printf("strng:'%.0d'\n", 0);
	  ft_putnbr(test);
	  ft_putchar(' ');
	  ft_putnbr(test2);
	  ft_putchar('\n');
	test = printf("tcchar :'{%-100.42d}'\n", 150);
	test2 = ft_printf("mcchar :'{%-100.42d}'\n", 150);
	ft_putnbr(test);
	ft_putchar(' ');
	ft_putnbr(test2);
	ft_putchar('\n');
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%#08.5x\n", 42);
	printf("%#08.5x\n", 42);

	return (0);
}
