/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:11:14 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/04 00:11:28 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_tags(char **fmt, char *opt, int *len)
{
	(*fmt)++;
	get_flags(fmt, opt);
	if (ft_isdigit(**fmt))
	{
		len[0] = ft_atoi(*fmt);
		*fmt += nb_len(len[0], 10);
	}
	get_precision(fmt, len);
	get_length(fmt, opt);
	opt[4] = **fmt;
}

void	get_flags(char **fmt, char *opt)
{
	while (**fmt && ft_strindexof("#+- 0", **fmt) != -1)
	{
		if (**fmt == '#')
			opt[0] = **fmt;
		if (**fmt == '0' && opt[1] != '-')
			opt[1] = **fmt;
		if (**fmt == '-')
			opt[1] = **fmt;
		if (**fmt == ' ' && opt[2] != '+')
			opt[2] = **fmt;
		if (**fmt == '+')
			opt[2] = **fmt;
		(*fmt)++;
	}
}

void	get_precision(char **fmt, int *len)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		if (ft_isdigit(*(*fmt)))
		{
			len[1] = ft_atoi(*fmt);
			*fmt += nb_len(len[1], 10);
		}
	}
	else
		len[1] = -1;
}

void	get_length(char **fmt, char *opt)
{
	while (ft_strchr("hl", **fmt))
	{
		if (**fmt == 'h' || **fmt == 'l')
		{
			if (**fmt == *(*fmt + 1))
			{
				opt[3] = **fmt - 32;
				(*fmt)++;
			}
			else
				opt[3] = **fmt;
		}
		(*fmt)++;
	}
}

int		ft_strindexof(const char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
