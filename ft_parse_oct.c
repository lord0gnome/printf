/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:10:41 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/19 15:27:45 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int	ft_parse_oct(unsigned long long n, char **str, t_form *info)
{
	long long	bck;
	char		*octstr;
	int			len;
	int			ret;

	bck = n;
	len = 1;
	if (n == 0)
		info->force = 0;
	while (bck /= 8)
		len++;
	ret = ft_det_zeroes(len + info->force, info, 0);
	octstr = (char *)malloc(sizeof(char) * (len + ret + info->force) + 1);
	octstr[len + ret + info->force] = '\0';
	bck = ret;
	while (ret-- > 0)
		octstr[ret + info->force] = '0';
	if (info->force == 1)
		octstr[0] = '0';
	ret = bck + len;
	while (len--)
	{
		octstr[len + bck + info->force] = (n % 8) + (48);
		n /= 8;
	}
	*str = octstr;
	return (ret + info->force);
}
