/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:46:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/15 16:34:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <wchar.h>

typedef struct		s_form
{
	int				prec;
	int				width;
	char			left;
	char			zero;
	char			space;
	char			plus;
	char			force;
	char			percent;
	char			type;

}					t_form;

typedef struct		s_data
{
	int	i;
	int	ib;
	int retplusreal;
	int	nargs;
	char type;
	char *string;
}					t_data;


typedef union		u_type
{
	unsigned char	hh;
	short			h;
	int				d;
	long			ld;
	long long		lld;
	unsigned int	x;
	char			*s;
	char			c;
	wint_t			wc;
	wchar_t			*ws;
	unsigned int	o;
	void			*p;
}					t_type;

int					ft_putll(long long n, char **str);
int					ft_putl(long n, char **str);
int					do_va_crap(va_list *current, t_data *d, t_type *var, t_form *info);
int					read_until(const char *restrict f, char *result, t_data *d);
int					ft_printf(const char *restrict format, ...);
int					modify_form(t_form *c, const char *restrict f, t_data *d);
int					reinit_form(t_form **form);
int					init_data(t_data **d);
int					isnum(char c);
int					check_prec(const char *restrict format);
int					isvalid(char c);
void				print_form(t_form *form);
int					ft_print_hex(long long n, char caps);
int					ft_print_bin(long long n);
int					ft_print_oct(unsigned long long n);
int					ft_atoi(const char *str);
char				*ft_strcpy(char *src, const char *dst);
char				*ft_strncpy(char *src, const char *dst, size_t n);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putchar(char c);
size_t				ft_strlen(const char *str);
int					print_int(t_form *info, t_data *d, int ret);
int					print_long(t_form *info, t_data *d, int ret);
int					print_char(t_form *info, t_data *d, int ret);
int					print_short(t_form *info, t_data *d, int ret);
int					ft_putcharspec(char n, char **str);
int					ft_print_nocon(t_form *info, int ret);
int					iscon(char c);

#endif
