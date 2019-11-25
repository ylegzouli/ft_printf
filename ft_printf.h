/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:12 by ylegzoul          #+#    #+#             */
/*   Upded: 2019/11/22 12:58:58 by ylegzoul         ###   ########.fr       */
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
	char	fl[NB_FLAG + 1];
	int		size;
	int		prec;
	char	type;
	char	*current;

	t_list	*elem;

	int		ptrnull;
	int		sizenull;
	char	espace;
	char	zero;
	char	moin;
	char	str_null[7];
}				t_arg;

int				ft_printf(const char *format, ...);
int				ft_start(const char *format, va_list *arg, t_list **li, 
t_arg **d);
int				ft_start_opt(char *next_arg, va_list *arg, t_list **li,
t_arg **d);
int				ft_init_d(t_arg **d);
void			ft_free_d(t_list **li, t_arg **d);

void			ft_def_flag(char *format, t_arg **d, va_list *arg);
void			ft_def_size(char *format, t_arg **d, va_list *arg);
void			ft_def_preci(char *format, t_arg **d, va_list *arg);
void			ft_def_type(char *format, va_list *arg, t_arg **d,
t_list **li);
char			ft_is_flag(char c);
char			ft_is_type(char c);


int				ft_convert(t_arg **d, va_list *arg);
int				ft_convert_char(t_arg **d, va_list *arg);
int				ft_convert_str(t_arg **d, va_list *arg);
int				ft_convert_ptr(t_arg **d, va_list *arg);
int				ft_convert_hexa(t_arg **d, va_list *arg);
int				ft_convert_unsigned(t_arg **d, va_list *arg);
int				ft_convert_int(t_arg **d, va_list *arg);
int				ft_convert_pcent(t_arg **d, va_list *arg);

int				ft_appli(t_arg **d, t_list **li);
int				ft_size(t_arg **d, int *len, int *len_e, t_list **cur);
int				ft_appli_preci(t_arg **d, t_list **cur, int len,
int len_e);
void			ft_appli_preci_pid(t_arg **d, t_list **cur, char **tmp, 
int len_e);
void            ft_appli_preci_str(t_arg **d, t_list **cur, int len, 
int len_e);
int				ft_appli_moin(t_arg **d, t_list **cur, int len,
int len_e);
int				ft_appli_zero(t_arg **d, t_list **cur, int len,
int len_e);
int				ft_appli_size(t_arg **d, t_list **cur, int len,
int len_e);

#endif
