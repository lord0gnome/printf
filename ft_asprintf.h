/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:17:04 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/06 17:26:07 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASPRINTF_H
# define FT_ASPRINTF_H

#include "ft_printf.h"
int	get_next_percent(const char *restrict format);
int	reinit_form(t_form **form);
int	isnum(char c);
int	check_prec(const char *restrict format);
int	isvalid(char c);

#endif
