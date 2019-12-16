/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 23:28:55 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/03 23:34:21 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			convert(va_list ap, char *opt, int *len, t_format string)
{
	long long int ret;

	ret = 0;
	if (ft_strindexof("diouxX", opt[4]) != -1)
	{
		ret = convert_nbr(ap, opt[4], opt);
		if (ret < 0 && ft_strindexof("dDi", opt[4]) != -1 &&
				ret != -9223372036854775807 - 1)
		{
			opt[2] = '-';
			ret *= -1;
		}
	}
	if (opt[4] == 's')
		string.str = va_arg(ap, char*);
	if (opt[4] == 'c')
		string.c = va_arg(ap, int);
	if (ft_strindexof("diouxX%%", opt[4]) != -1)
		print_nbr(opt, len, ret);
	else if (opt[4] == 's')
		print_str(opt, len, string);
	else if (opt[4] == 'c')
		print_c(len, opt, string);
	else if (opt[4] == 'p')
		print_p(ap, len);
}

long long int	convert_nbr(va_list ap, char c, char *opt)
{
	long long int ret;

	ret = 0;
	if (opt[3])
	{
		if (ft_strindexof("di", c) != -1)
			ret = convert_int(ap, opt[3]);
		else if (ft_strindexof("uoxX", c) != -1)
			ret = convert_uint(ap, opt[3]);
	}
	else
	{
		if (ft_strchr("di", c))
			ret = va_arg(ap, int);
		else if (ft_strchr("uoxX", c))
			ret = va_arg(ap, unsigned int);
	}
	return (ret);
}

long long int	convert_int(va_list ap, char opt3)
{
	long long int ret;

	ret = 0;
	if (opt3 == 'H')
	{
		ret = va_arg(ap, int);
		ret = (char)ret;
	}
	else if (opt3 == 'h')
		ret = (short)va_arg(ap, int);
	else if (opt3 == 'l')
		ret = va_arg(ap, long);
	else if (opt3 == 'L')
		ret = va_arg(ap, long long);
	return (ret);
}

long long int	convert_uint(va_list ap, char opt3)
{
	long long int ret;

	ret = 0;
	if (opt3 == 'H')
	{
		ret = va_arg(ap, unsigned int);
		ret = (unsigned char)ret;
	}
	else if (opt3 == 'h')
		ret = (unsigned short)va_arg(ap, unsigned int);
	else if (opt3 == 'l')
		ret = va_arg(ap, unsigned long);
	else if (opt3 == 'L')
		ret = va_arg(ap, unsigned long long);
	return (ret);
}

void			print_p(va_list ap, int *len)
{
	long long int	p;

	p = va_arg(ap, long long);
	ft_putstr("0x");
	ft_putstr(ft_itoa_base(p, 16, 'p'));
	len[3] += ft_strlen(ft_itoa_base(p, 16, 'p')) + 2;
}
