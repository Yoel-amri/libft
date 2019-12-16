/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 23:44:50 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/03 23:46:21 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_character(long long int nb, int base, char opt4)
{
	char	b;

	b = (opt4 == 'X') ? 'A' : 'a';
	nb %= base;
	if (nb < 10)
		return (nb + '0');
	nb %= 10;
	return (b + nb);
}

char	*ft_itoa_base(long long int num, int base, char opt4)
{
	char	*res;
	int		sign;
	int		size;
	int		i;

	sign = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
		sign += (base == 10) ? 1 : 0;
	size = nb_len(num, base);
	if (!(res = (char *)ft_memalloc(size + sign + 1)))
		return (NULL);
	i = size + sign - 1;
	while (num != 0)
	{
		res[i] = ft_character(num, base, opt4);
		num /= base;
		i--;
	}
	res[i] = (sign == 1) ? '-' : res[i];
	res[size] = '\0';
	return (res);
}

void	id_base(char *opt, int *len)
{
	if (opt[4] == 'x' || opt[4] == 'X' || opt[4] == 'p')
		len[2] = 16;
	else if (opt[4] == 'o')
		len[2] = 8;
	else
		len[2] = 10;
	if (opt[4] == '%')
		len[2] = -1;
}

char	*ft_uitoa_base(unsigned long long int value, int base, char c)
{
	char	*res;
	int		size;
	int		i;

	if (value == 0)
		return (ft_strdup("0"));
	else
	{
		size = unblen(value, base);
		if (!(res = (char *)ft_memalloc(size + 1)))
			return (NULL);
		i = size - 1;
		while (value != 0)
		{
			res[i] = uft_charachter(value, base, c);
			value /= base;
			i--;
		}
		res[size] = '\0';
	}
	return (res);
}

char	uft_charachter(unsigned long long int value, int base, char c)
{
	char	b;

	b = (c == 'X') ? 'A' : 'a';
	value %= base;
	if (value < 10)
		return (value + '0');
	value %= 10;
	return (b + value);
}
