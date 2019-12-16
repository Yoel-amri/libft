/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 23:47:32 by yel-amri          #+#    #+#             */
/*   Updated: 2019/01/04 00:02:22 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	int			len[4];
	char		opt[5];
	va_list		va;
	t_format	string;

	len[3] = 0;
	va_start(va, fmt);
	while (*fmt)
		if (*fmt == '%')
		{
			set_params(len, opt, &string);
			get_tags(&fmt, opt, len);
			if (ft_strchr("cspdiouxX%%", opt[4]))
				convert(va, opt, len, string);
			fmt++;
		}
		else
		{
			len[3] += 1;
			ft_putchar(*fmt);
			fmt++;
		}
	va_end(va);
	return (len[3]);
}
