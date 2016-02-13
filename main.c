/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/13 14:23:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	printf("print and get cut off by a \\0 character\n\0 test");
	printf("print an empty string '%10-s'\n", "");
	printf("find out if when not next to conversion spc '%h l l hd'\n",500);
	printf("print a number larger than an int with '%ld'\n", 2000000000);
	printf("prints stuff inside of too many %d\n", sizeof(long));
	ft_printf("%ld",400000000000);
	return (0);
}
