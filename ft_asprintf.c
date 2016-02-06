/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:56:04 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/06 17:27:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h> //	REMOVE BEFORE PUSHING
#include "libft/libft.h"
#include "ft_asprintf.h"



int	modify_form(t_form *c, const char *restrict f)
{
	int		i;
	int		bck;

	i = get_next_percent(f + i);
	if (i >= 0)
	{
		while (isvalid(f[i]))
		{
			if (f[i] == '+')
			{
				c->plus = 1;
				c->space = 0;
			}
			if (f[i] == ' ' && !c->plus)
				c->space = 1;
			if (f[i] == '-')
			{
				c->left = 1;
				c->zero = 0;
			}
			if (f[i] == '0' && !c->left && (f[i - 1] == '%' || !isnum(f[i - 1])))
				c->zero = 1;
			if (f[i] == '#')
				c->force = 1;
			if (f[i] == '.')
			{
				c->prec = check_prec(f + i++);
				while (isnum(f[i + 1]))
					i++;
				i++;
				continue ;
			}
			if (isnum(f[i]) && f[i - 1] != '.')
			{
				bck = c->width;
				c->width = ft_atoi(f + i);
				if (c->width == 0)
					c->width = bck;
				while (isnum(f[i + 1]))
					i++;
			}
			i++;
		}
	}
	return (i);
}

int	ft_asprintf(char **ret, const char * restrict format, ...)
{
	va_list	ap;
	t_form	*c;
	int		i;

	i = 0;
	//tests
	reinit_form(&c);
	i = modify_form(c, format);
	printf("precision :%15d\nspace     :%15d\nzero      :%15d\nleft      :%15d\nplus      :%15d\nforce     :%15d\nwidth     :%15d\n", c->prec, c->space, c->zero, c->left, c->plus, c->force, c->width);
	reinit_form(&c);
	modify_form(c, format);
	printf("precision :%15d\nspace     :%15d\nzero      :%15d\nleft      :%15d\nplus      :%15d\nforce     :%15d\nwidth     :%15d\n", c->prec, c->space, c->zero, c->left, c->plus, c->force, c->width);
	return (0);
}

int main(void)
{
	const char *restrict format;
	char *string;
	int test;
	char *ret;
	int	i;

	i = 1;
	string = "test\0";
	format = " %#+42533253-3349845.4-d       %42d";
	test = ft_asprintf(&ret, format, string);
}
