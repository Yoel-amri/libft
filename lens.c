/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 23:38:14 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/03 23:44:03 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_len(long long int nbr, int base)
{
	int	size;

	size = (nbr < 0) ? 1 : 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

int		maxnbr(char *opt, int *len, long long int nbr)
{
	int		max;
	int		nbrofdigits;

	nbrofdigits = 0;
	id_base(opt, len);
	if (ft_strindexof("di", opt[4]) != -1)
		nbrofdigits += nb_len(nbr, len[2]);
	else
		nbrofdigits += unblen((unsigned long long)nbr, len[2]);
	max = (nbrofdigits > len[1]) ? nbrofdigits : len[1];
	if (max == len[1] && !len[0] && (opt[4] == 'o' || opt[4] == 'O'))
		max--;
	if ((opt[0] == '#' && (opt[4] == 'o' || opt[4] == 'O')) ||
			(opt[2] && opt[4] != '%' && opt[4] != 'u'))
		max++;
	if (opt[0] == '#' && nbr != 0 && (opt[4] == 'x' || opt[4] == 'X'))
		max += 2;
	if (!nbr && !len[1] && opt[4] != '%')
		max--;
	return (max);
}

int		unblen(unsigned long long int value, int base)
{
	int	size;

	size = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

void	set_params(int *len, char *opt, t_format *string)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (i < 3)
			len[i] = 0;
		opt[i] = 0;
		i++;
	}
	(*string).c = 0;
	(*string).str = 0;
}

int		maxstr(t_format string, int *len)
{
	int max;

	if (string.str == NULL)
		return (-1);
	max = ft_strlen(string.str);
	if (len[1] >= 0)
		return (max > len[1] ? len[1] : max);
	else
		return (max);
}
