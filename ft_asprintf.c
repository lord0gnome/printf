/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:56:04 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/02 14:21:22 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

int *detect_type_and_stock(char *ret, const char * restrict format)
{
	int		i;
	size_t	ret_len;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			if (format[i + 1])
				if (format[i + 1] == 'i' || format[i] == 'd')
					

	}

}

int	ft_asprintf(char **ret, const char * restrict format, ...)
{
	va_list	ap;
	int		i;
	int 	type;
	int		last;
	char	*types;

	type = 0;
	i = -1;
	va_start(ap, format);
	if (!format)
		return (-1);
	if (!ret)
		return (-1);
	while (format[++i])
	{
		last = detect_type_and_stock(types, format + i);
		i += last;
	}
	if (type == 1)
		*ret = va_arg(ap, char *);
	ft_putstr(*ret);
	va_end(ap);
				
	return (type);
}

int main(void)
{
	const char * restrict format;
	char *ret;
	char *string;
	int test;

	ret = (char *)malloc(sizeof(char) * 5);
	string = "test\0";
	format = "%s";
	test = ft_asprintf(&ret, format, string);
}
