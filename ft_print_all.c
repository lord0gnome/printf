/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:36:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/08 15:49:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	print_wstr(t_form *info, int ret, wchar_t *str)
{
	int newret;
	int index;
	int count;

	newret = 0;
	index = 0;
	if (info->prec != -1 && info->prec < ret)
		ret = info->prec;
	count = info->prec;
	if (count == -1 || count > ret)
		count = ret;
	if (info->left == 0)
	{
		while (info->width - count > 0)
		{
			if (info->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			newret++;
			info->width--;
		}
		ft_putwidestr(str, info->prec);

	}
	else if (info->left == 1)
	{
		ft_putwidestr(str, info->prec);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret + index);
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
		count = ret;
	if (info->left == 0)
	{
		while (info->width - count > 0)
		{
			if (info->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			newret++;
			info->width--;
		}
		ft_putstr(d->string);

	}
	else if (info->left == 1)
	{
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
	char ospace;
	int bck;

	bck = info->prec;
	d->neg = d->string[0] == '-' && (info->zero == 1 || info->prec > 0) ? 1 : 0;
	ospace = info->zero == 1  && info->prec < 0 ? '0' : ' ';
	newret = 0;
	if (info->prec == -1 || info->prec < ret - d->neg)
		info->prec = ret - d->neg;
	if (info->width == -1)
		info->width = 0;
	if (info->left == 0)
	{
		if (d->string[0] != '-' && (info->plus || info->space))
		{
			ft_putchar(info->plus ? '+' : ' ');
			ret++;
			info->width--;
		}
		if (d->neg && info->zero == 1)
			ft_putchar(*d->string++);
		while (info->width - (info->prec - (ret - d->neg)) - ret > 0)
		{
			newret++;
			ft_putchar(ospace);
			info->width--;
		}
		if (d->neg && !info->zero)
			ft_putchar(*d->string++);
		while (info->prec - (ret - d->neg) > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		if (*d->string == '0' && bck == 0)
			newret--;
		else
			ft_putstr(d->string);
	}
	else if (info->left == 1)
	{
		if (d->string[0] == '-' && info->zero == 1)
			ft_putchar(*d->string++);
		else if (d->string[0] != '-' && (info->plus || info->space))
		{
			ft_putchar(info->plus ? '+' : ' ');
			ret++;
		}
		while (info->prec - (ret) > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		if (*d->string == '0' && bck == 0)
			newret--;
		else
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

int	do_info_norm(t_form *info, t_data *d, int newret, int ret)
{
	if (info->left == 0)
	{
		if (info->force == 1)
		{
			if ((d->type == 'o' || d->type == 'O'))
			{
				ft_putchar(*d->string++);
				info->width--;
			}
			else if ((d->type == 'x' || d->type == 'X') && info->force)
			{
				ft_putchar(*d->string++);
				ft_putchar(*d->string++);
				info->width -= 2;
			}
		}
		while (info->width - (info->prec - ret) - ret > 0)
		{
			newret++;
			ft_putchar(d->ospace);
			info->width--;
		}
		while (info->prec - (ret) > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		if (*d->string == '0' && d->bck == 0 + (info->force * 2))
			newret--;
		else
			ft_putstr(d->string);
	}
	return (newret);
}

int	do_info_left(t_form *info, t_data *d, int newret, int ret)
{
	if (info->left == 1)
	{
		while (info->prec - ret > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		if (*d->string == '0' && d->bck == 0)
			newret--;
		else
			ft_putstr(d->string);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (newret);
}

int	print_longu(t_form *info, t_data *d, int ret)
{
	int newret;

	d->bck = info->prec;
	d->ospace = info->zero == 1  && info->prec < 0 ? '0' : ' ';
	newret = 0;
	if (info->prec == -1 || info->prec < ret)
		info->prec = ret;
	if (info->width == -1)
		info->width = 0;
	newret = do_info_norm(info, d, newret, ret);
	newret = do_info_left(info, d, newret, ret);
	return (ret + newret);
}

int	print_char(t_form *info, t_data *d, int ret)
{
	int newret;

	newret = 0;
	d->neg = 0;
	if (info->left == 0)
	{
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			newret++;
			info->width--;
		}
		newret += ret;
		while (ret--)
			ft_putchar(d->string[d->neg++]);
	}
	else
	{
		newret += ret;
		while (ret--)
			ft_putchar(d->string[d->neg++]);
		ret = newret;
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			newret++;
			info->width--;
		}
	}


	return (newret);
}
/*
   if (info->left == 0)
   {
   while (info->width - ret > 0)
   {
   ft_putchar(' ');
   newret++;
   info->width--;
   }
   while (info->zero == 1 && ret -1)
   {
   ft_putchar((*d->string));
   d->string++;
   }
   ft_putchar((*d->string));

   }
   else if (info->left == 1)
   {
   ft_putchar(d->string[0]);
   while (info->width - ret > 0)
   {
   ft_putchar(' ');
   info->width--;
   newret++;
   }
   }
   return (ret + newret);
   }*/
int	do_info_normp(t_form *info, t_data *d, int newret, int ret)
{
	d->neg = 0;
	if (info->left == 0)
	{
			if (info->zero)
			{
				ft_putchar(d->string[d->neg++]);
				ft_putchar(d->string[d->neg++]);
				info->bigsmall = 2;
			}
		while (info->width - (info->prec - ret) - ret > 0)
		{
			newret++;
			ft_putchar(d->ospace);
			info->width--;
		}
			if (d->type == 'p' && info->bigsmall != 2)
			{
				ft_putchar(d->string[d->neg++]);
				ft_putchar(d->string[d->neg++]);
				info->width -= 2;
				info->bigsmall = 2;
			}
		while (info->prec - (ret) > 0)
		{
			newret++;
			ft_putchar('0');
			info->prec--;
		}
		if (d->string[d->neg] == '0' && d->bck == 0)
			newret--;
		else
		ft_putstr(d->string + d->neg);
	}
	return (newret);
}

int	do_info_leftp(t_form *info, t_data *d, int newret, int ret)
{
	if (info->left == 1)
	{
		while (info->prec - ret > 0)
		{
			ft_putchar('0');
			if (info->width > 0)
				info->width--;
			if (info->prec > 0)
				info->prec--;
			newret++;
		}
		if (*d->string == '0' && d->bck == 0)
			newret--;
		else
			ft_putstr(d->string);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (newret);
}

int	print_longp(t_form *info, t_data *d, int ret)
{
	int newret;

	d->bck = info->prec;
	d->ospace = info->zero == 1  && info->prec < 0 ? '0' : ' ';
	newret = 0;
	if (info->prec == -1 || info->prec < ret)
		info->prec = ret;
	if (info->width == -1)
		info->width = 0;
	newret = do_info_norm(info, d, newret, ret);
	newret = do_info_left(info, d, newret, ret);
	return (ret + newret);
}
