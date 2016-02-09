/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:46:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/09 16:43:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/libft.h"

typedef struct		s_form
{
	int			prec;
	int			width;
	char		left;
	char		zero;
	char		space;
	char		plus;
	char		force;
	char		percent;
}					t_form;

int	read_until(const char *restrict f, char *result);
int	ft_printf(void); //to change!!
int	modify_form(t_form *c, const char *restrict f);
int	reinit_form(t_form **form);
int	isnum(char c);
int	check_prec(const char *restrict format);
int	isvalid(char c);
void	print_form(t_form *form);

#endif
