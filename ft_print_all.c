/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:36:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/19 14:20:02 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	if (info->prec < 0)
		info->prec = 0;
	if (info->width < 0)
		info->width = 0;
	if (info->left == 0)
	{
		while (info->width - info->prec - ret > 0)
		{
			newret++;
			ft_putchar(' ');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
		}
		while (info->prec - ret > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		if (d->string)
			ft_putstr(d->string);
	}
	else if (info->left == 1)
	{
		while (info->prec - info->width - ret > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		ft_putstr(d->string);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret);
}
int	print_str(t_form *info, t_data *d, int ret)
{
	int newret;
	int index;
	int count;

	newret = 0;
	index = 0;
	if (info->prec > ret)
		info->prec = ret;
	count = info->prec;
	if (count == -1)
		count = 0;

	if (info->left == 0)
	{
		while (info->width > 0 && info->width - count > 0)
		{
			ft_putchar(' ');
			newret++;
			info->width--;
		}
		if (info->prec != -1)
		{
			ret = 0;
			while (count--)
			{
				ft_putchar(d->string[index++]);
			}
		}
		else
			ft_putstr(d->string);

	}



	else if (info->left == 1)
	{
		if (info->prec != -1)
		{
			while (info->prec-- > 0 && d->string[index])
				ft_putchar(d->string[index++]);
			ret -= ft_strlen(d->string);
		}
		else
			ft_putstr(d->string);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret + index);
}
/*int	print_long(long d, t_form *info, t_data *d)
  int	print_long_long(long long d, t_form *info, t_data *d)
  int	print_hex(unsigned int d, t_form *info, t_data *d)
  int	print_long_hex(long unsigned int d, t_form *info, t_data *d)
  int	print_long_long_hex(long long unsigned int d, t_form *info, t_data *d)
  int	print_octal(unsigned int d, t_form *info, t_data *d)
  int	print_int(int d, t_form *info, t_data *d)*/
int	ft_print_nocon(t_form *info, int ret)
{
	int newret;

	char ospace;

	ospace = info->zero == 1 ? '0' : ' ';
	newret = 0;
	if (info->prec == -1)
		info->prec = 0;
	if (info->width == -1)
		info->width = 0;
	if (info->left == 0)
	{
		while (info->width - ret > 0)
		{
			newret++;
			ft_putchar(ospace);
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
		}
	}
	else if (info->left == 1)
	{
		while (info->prec - info->width - ret > 0)
		{
			ft_putchar(ospace);
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		while (info->width - ret)
		{
			ft_putchar(ospace);
			info->width--;
			newret++;
		}
	}
	return (ret + newret);
}

int	print_long(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	if (info->prec == -1)
		info->prec = 0;
	if (info->width == -1)
		info->width = 0;
	if (info->left == 0)
	{
		while (info->width - info->prec - ret > 0)
		{
			newret++;
			ft_putchar(' ');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
		}
		while (info->prec - ret > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		ft_putstr(d->string);
	}
	else if (info->left == 1)
	{
		while (info->prec - info->width - ret > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		ft_putstr(d->string);
		while (info->width - ret)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret);
}
int	print_char(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	if (info->prec == -1)
		info->prec = 0;
	if (info->width == -1)
		info->width = 0;
	if (info->left == 0)
	{
		while (info->width - info->prec - ret > 0)
		{
			newret++;
			ft_putchar(' ');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
		}
		while (info->prec - ret > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		ft_putstr(d->string);
	}
	else if (info->left == 1)
	{
		while (info->prec - info->width - ret > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		ft_putstr(d->string);
		while (info->width - ret)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret);
}
