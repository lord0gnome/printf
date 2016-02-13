/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/13 17:16:51 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	char test;

	test = 'c';
	printf("adress of char %p\n", &test);
	printf("print octal 42 : '%10#o'\n", 42);
	ft_printf("%X\n",400000000000);
	ft_printf("%X\n",400000000000);
	ft_print_hex(0, 0);
	ft_putchar('\n');
	ft_print_bin(4324242391115995239);
	ft_putchar('\n');
	ft_putstr("0x");
	ft_print_hex(&test, 0);
	return (0);
}
