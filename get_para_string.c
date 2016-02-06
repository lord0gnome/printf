/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_para_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:07:32 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/04 13:52:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*get_para_string_indexes(const char *restrict format)
{
	size_t	total;
	int		i;
	int		*ret;

	total = 0;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			
		}
	ret = (int *)malloc(sizeof(int) * total); // implement errors
	ret[0] = total;
	total = 1;
	while (format[++i])
		if (format[i] == '%')
		{
			ret[total++] = i;
			if (format[i + 1] && format[i + 1] == '%')
				i++;
		}
	return (ret);
}

size_t	find_flags(const char *restrict format, int index)
{
	int	i;

	i = ;
	while ((tab[0] + 1) - i)
	{
		
	}
}
