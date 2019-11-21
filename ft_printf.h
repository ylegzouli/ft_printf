/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:12 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 19:14:32 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define FLAG "-0"

# define NB_FLAG 2

typedef struct	s_arg
{
	char	flags[NB_FLAG + 1];
	int		size;
	int		precision;
	char	type;
	char	*current;

	t_list	*elem;

	char	espace;
	char	zero;
	char	moin;
	char	str_null[7];
}				t_arg;

int				ft_printf(const char *format, ...);
int				ft_start_printf(const char *format, va_list *arg, t_list **li);
int				ft_start_opt(char *next_arg, va_list *arg, t_list **li,
t_arg **data);
int				ft_init_data(t_arg **data);
void			ft_free_data(t_list **li);

void			ft_def_flag(char *format, t_arg **data, va_list *arg);
void			ft_def_size(char *format, t_arg **data, va_list *arg);
void			ft_def_preci(char *format, t_arg **data, va_list *arg);
void			ft_def_type(char *format, va_list *arg, t_arg **data,
t_list **li);
char			ft_is_flag(char c);
char			ft_is_type(char c);


int				ft_convert(t_arg **data, va_list *arg);
int				ft_convert_char(t_arg **data, va_list *arg);
int				ft_convert_str(t_arg **data, va_list *arg);
int				ft_convert_ptr(t_arg **data, va_list *arg);
int				ft_convert_hexa(t_arg **data, va_list *arg);
int				ft_convert_unsigned(t_arg **data, va_list *arg);
int				ft_convert_int(t_arg **data, va_list *arg);
int				ft_convert_pcent(t_arg **data, va_list *arg);

int				ft_appli(t_arg **data, t_list **li);
int				ft_appli_preci(t_arg **data, t_list **cur, int len,
int len_elem);
int				ft_appli_moin(t_arg **data, t_list **cur, int len,
int len_elem);
int				ft_appli_zero(t_arg **data, t_list **cur, int len,
int len_elem);
int				ft_appli_size(t_arg **data, t_list **cur, int len,
int len_elem);

#endif
