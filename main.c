/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:33:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 18:20:58 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	printf("print and get cut off by a \\0 character\n\0 test");
	printf("print an empty string '%10-s'\n", "");
	printf("print a null string '%10-s'\n", NULL);
	printf("print a number larger than an int with %%D '%42 10d'\n", 424);
	ft_printf();
	return (0);
}
