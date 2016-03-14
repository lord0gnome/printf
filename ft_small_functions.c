/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:03:28 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 17:53:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	read_until(const char *restrict f, char *result, t_data *d)
{
	char	*bck;
	int		i;

	i = 0;
	bck = result;
	while (f[i] && f[i] != '%')
		i++;
	if (bck)
	{
		result = (char *)malloc(sizeof(char) * (i + 1) + ft_strlen(bck));
		ft_strcpy(result, bck);
		ft_strncpy(result + ft_strlen(bck), f, i);
		result[ft_strlen(bck) + i] = '\0';
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (i + 1));
		ft_strncpy(result, f, i);
		result[i] = '\0';
	}
	if (result)
		ft_putstr(result);
	free(result);
	d->retplusreal += i;
	return (i);
}

int	reinit_form(t_form **form)
{
	if (!(*form = (t_form *)malloc(sizeof(t_form))))
		return (-1);
	(*form)->prec = -1;
	(*form)->width = -1;
	(*form)->left = 0;
	(*form)->zero = 0;
	(*form)->space = 0;
	(*form)->plus = 0;
	(*form)->force = 0;
	(*form)->percent = -1;
	(*form)->type = 0;
	(*form)->bigsmall = 0;
	(*form)->nega = 0;
	return (1);
}

int	init_data(t_data **d)
{
	if (!(*d = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	(*d)->i = 0;
	(*d)->ib = 42;
	(*d)->retplusreal = 0;
	(*d)->nargs = 0;
	(*d)->string = NULL;
	(*d)->type = 0;
	(*d)->ospace = ' ';
	(*d)->bck = -1;
	(*d)->neg = 0;
	(*d)->tmp = 0;
	return (1);
}
