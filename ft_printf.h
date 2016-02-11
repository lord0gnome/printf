/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:46:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/11 13:20:33 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <wchar.h>
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

typedef struct	s_data
{
	int	ret;
	int	retbck;
	int	nargs;
}				t_data;


typedef union	u_type
{
	unsigned char	hh;
	int			d;
	long		ld;
	long long	lld;
	char		*s;
	char		c;
	wint_t		wc;
	wchar_t		*ws;
}				t_type;

int	read_until(const char *restrict f, char *result);
int	ft_printf(const char *restrict format, ...);
int	modify_form(t_form *c, const char *restrict f, t_data *d);
int	reinit_form(t_form **form);
int	isnum(char c);
int	check_prec(const char *restrict format);
int	isvalid(char c);
void	print_form(t_form *form);

#endif
