/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:46:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/02 16:39:37 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct			s_form
{
	int					prec;
	int					width;
	char				left;
	char				zero;
	char				space;
	char				plus;
	char				force;
	char				percent;
	char				type;
	char				bigsmall;
	int					nega;
}						t_form;

typedef struct			s_data
{
	int					i;
	int					ib;
	int					retplusreal;
	int					nargs;
	char				type;
	char				*string;
	char				ospace;
	int					neg;
	int					bck;
	int					tmp;
}						t_data;

typedef struct			s_mask
{
	unsigned int		m0;
	unsigned int		m1;
	unsigned int		m2;
	unsigned int		m3;
	unsigned char		c0;
	unsigned char		c1;
	unsigned char		c2;
	unsigned char		c3;
	signed int			binlen;
	int					res;
	unsigned int		v;
	unsigned char		octet;
}						t_mask;

typedef union			u_type
{
	unsigned char		hh;
	unsigned short		uh;
	short				h;
	int					d;
	long				ld;
	long long			lld;
	unsigned int		x;
	char				*s;
	char				c;
	wchar_t				wc;
	wchar_t				*ws;
	unsigned int		o;
	unsigned long int	lo;
	unsigned long long	llu;
	void				*p;
	size_t				z;
	intmax_t			im;
	uintmax_t			uim;
}						t_type;

int						ft_printf(const char *restrict format, ...);
int						do_va(va_list *now, t_data *d, t_type *var, t_form *i);
int						read_until(const char *restrict f, char *r, t_data *d);
int						reinit_form(t_form **form);
int						init_data_prntf(t_data **d);
int						modify_f(t_form *c, const char *restrict f, t_data *d);
void					ft_putcharprntf(char c);
int						isnum(char c);
int						isvalid(char c);
int						iscon(char c);
int						binlen(int n);
int						check_prec(const char *restrict format);
char					*itoabase(long long n, int base, char caps);
char					*itoabaseu(uintmax_t n, int base, char caps);
char					*itoabasex(t_form *info, size_t n, int base, char caps);
char					*itoabaseo(t_form *info, size_t n, int base);
char					*itoabasep(t_form *info, size_t n, int base, char caps);
int						print_str(t_form *info, t_data *d, int ret);
int						print_wstr(t_form *info, int ret, wchar_t *str);
int						print_long(t_form *info, t_data *d, int ret);
int						print_unsigned(t_form *i, t_data *d, int ret);
int						print_char(t_form *info, t_data *d, int ret);
int						print_short(t_form *info, t_data *d, int ret);
int						print_nocon(t_form *info, int ret);
int						han_int(va_list *now, t_data *d, t_type *v, t_form *i);
void					han_int2(va_list *now, t_data *d, t_type *v, t_form *i);
int						han_oct(va_list *now, t_data *d, t_type *v, t_form *i);
void					han_oct2(va_list *now, t_data *d, t_type *v, t_form *i);
int						han_hex(va_list *now, t_data *d, t_type *v, t_form *i);
void					han_hex2(va_list *now, t_data *d, t_type *v, t_form *i);
int						han_nsg(va_list *now, t_data *d, t_type *v, t_form *i);
void					han_nsg2(va_list *now, t_data *d, t_type *v, t_form *i);
void					decide_force(t_form *info, t_data *d);
void					decide_force_left(t_form *info, t_data *d);
int						do_binlen7(t_mask n, t_form *i, int *ret, wchar_t *str);
int						do_binlen11(t_mask n, t_form *i, int *ret);
int						do_binlen16(t_mask n, t_form *i, int *ret);
int						do_others(t_mask n, t_form *i, int *ret);
void					forceretcaps(char *str, int caps);
int						test_chr(t_mask n, t_form *i, int *ret, wchar_t *str);
int						ft_det_zeroes(int len, t_form *info, int sign);
int						ft_det_zeroes_ptr(int len, t_form *info, int sign);
int						ft_putcharprntfstr(char c, char **into, t_form *info);
int						ft_putwidechar(wchar_t *chr);
int						ft_putwidestr(wchar_t *chr, t_form *i);
int						get_wstrlen(wchar_t *chr, t_form *i);
char					*ft_putstrstr(char *input, t_form *info);
int						get_wstrlen(wchar_t *str, t_form *i);
int						ft_atoi(const char *str);
char					*ft_strcpy(char *src, const char *dst);
char					*ft_strncpy(char *src, const char *dst, size_t n);
void					ft_putstr(char const *s);
void					ft_putnbr(int n);
void					*ft_memset(void *b, int c, size_t n);
size_t					ft_strlen(const char *str);

#endif
