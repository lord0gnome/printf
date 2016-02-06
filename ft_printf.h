/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:03:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/06 15:49:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct		s_form
{
	int			prec;
	int			width;
	char		left;
	char		zero;
	char		space;
	char		plus;
	char		force;

	struct s_form	*next;
}					t_form;

#endif
