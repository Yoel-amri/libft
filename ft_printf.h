/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <yel-amri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:11:49 by yel-amri          #+#    #+#             */
/*   Updated: 2019/12/15 23:41:00 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct	s_format
{
	int		c;
	char	*str;
}				t_format;

int				nb_len(long long int nbr, int base);
int				ft_printf(char *fmt, ...);
void			get_flags(char **fmt, char *opt);
void			get_length(char **fmt, char *opt);
void			get_precision(char **fmt, int *len);
void			get_tags(char **fmt, char *opt, int *len);
long long int	convert_nbr(va_list ap, char c, char *opt);
long long int	convert_int(va_list ap, char opt3);
long long int	convert_uint(va_list ap, char opt3);
void			convert(va_list ap, char *opt, int *len, t_format string);
void			print_nbr(char *opt, int *len, long long int nbr);
void			print_opt(char *opt, int *len, long long int nbr, int max);
void			print_nbrbase(long long int nbr, int base, char opt4);
int				nb_len(long long int nbr, int base);
int				unb_len(long long int nbr, int base);
void			id_base(char *opt, int *len);
int				maxnbr(char *opt, int *len, long long int nbr);
char			ft_character(long long int num, int base, char opt4);
char			*ft_itoa_base(long long int num, int base, char opt4);
int				ft_printf(char *fmt, ...);
void			set_params(int *len, char *opt, t_format *string);
void			ft_putnchar(char c, int n);
int				ft_strindexof(const char *str, char c);
int				unblen(unsigned long long int value, int base);
void			print_str(char *opt, int *len, t_format string);
int				maxstr(t_format string, int *len);
void			print_c(int *len, char *opt, t_format string);
void			print_p(va_list ap, int *len);
char			*ft_uitoa_base(unsigned long long int value, int base, char c);
char			uft_charachter(unsigned long long int value, int base, char c);

#endif
