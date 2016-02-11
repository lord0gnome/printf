/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/11 14:09:59 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	printf("print and get cut off by a \\0 character\n\0 test");
	printf("print an empty string '%10-s'\n", "");
	printf("find out if ll and others work when not next to conversion spc '%l10-d'\n",199999999);
	printf("print a number larger than an int with %%D '%42 10D'\n", 42242424242);
	printf("prints stuff inside of too many %% signs. %%%%%d%%%%\n", 42);
	ft_printf("%s %d", "My number is", 42);
	return (0);
}
