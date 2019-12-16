/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:03:04 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/04 00:08:55 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_nbr(char *opt, int *len, long long int nbr)
{
	int max;
	int stock;

	if (!nbr && len[1] == -1 && opt[4] == 'o' && opt[0] == '#')
		len[1] = 0;
	max = maxnbr(opt, len, nbr);
	stock = (max > len[0]) ? max : len[0];
	stock = (stock > len[1]) ? stock : len[1];
	len[3] += stock;
	print_opt(opt, len, nbr, max);
	if (opt[4] == '%')
		ft_putchar('%');
	if ((nbr || len[1]) && opt[4] != '%')
		print_nbrbase(nbr, len[2], opt[4]);
	if (opt[1] == '-' && len[0] > len[1])
		ft_putnchar(' ', len[0] - max);
}

void		print_opt(char *opt, int *len, long long int nbr, int max)
{
	if (!opt[1] || (opt[1] == '0' && len[1] >= 0))
		ft_putnchar(' ', len[0] - max);
	if (opt[2] && opt[4] != '%' && opt[4] != 'u')
		write(1, &opt[2], 1);
	if (opt[0] == '#')
	{
		if (opt[4] == 'x' && nbr != 0)
			write(1, "0x", 2);
		else if (opt[4] == 'X' && nbr != 0)
			write(1, "0X", 2);
		else if (opt[4] == 'o')
		{
			write(1, "0", 1);
			len[1] -= len[1] > 0 ? 1 : 0;
		}
	}
	if (opt[1] == '0' && len[1] == -1)
		ft_putnchar('0', len[0] - max);
	if (len[1] > 0)
		ft_putnchar('0', len[1] - nb_len(nbr, len[2]));
}

void		print_nbrbase(long long int nbr, int base, char opt4)
{
	char *out;

	if (ft_strindexof("di", opt4) != -1)
	{
		out = (nbr == -9223372036854775807 - 1) ?
			ft_strdup("-9223372036854775808") : ft_itoa_base(nbr, base, opt4);
		ft_putstr(out);
	}
	else
		ft_putstr(ft_uitoa_base(nbr, base, opt4));
}

void		print_str(char *opt, int *len, t_format string)
{
	int max;
	int i;

	i = -1;
	max = maxstr(string, len);
	if (max == -1)
	{
		ft_putstr("(null)");
		len[3] += 6;
	}
	if (len[0] > max && opt[1] != '-' && max != -1)
	{
		ft_putnchar(' ', len[0] - max);
		len[3] += len[0] - max;
	}
	while (++i < max && max != -1)
	{
		ft_putchar(string.str[i]);
		len[3] += 1;
	}
	if (opt[1] == '-' && len[0] >= max && max != -1)
	{
		ft_putnchar(' ', len[0] - max);
		len[3] += len[0] - max;
	}
}

void		print_c(int *len, char *opt, t_format string)
{
	if (len[0] > 0 && opt[1] != '-')
	{
		ft_putnchar(' ', len[0] - 1);
		len[3] += len[0] - 1;
	}
	ft_putchar(string.c);
	if (opt[1] == '-' && len[0] > 0)
	{
		ft_putnchar(' ', len[0] - 1);
		len[3] += len[0] - 1;
	}
	len[3]++;
}
