/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:12 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/17 14:55:15 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define FLAG "-0"

# define NB_FLAG 2

typedef struct	s_arg
{
	char	flags[NB_FLAG + 1];
	int		precision;
	char 	*current;
	
	t_list	*elem;
	int		size;
	char	type;
	
	char	espace;
	char	zero;
}				t_arg;

int         ft_printf(const char *format, ...);
void		ft_start_printf(const char *format, va_list *arg, t_list **li);
void		ft_init_data(t_arg **argument);
void		ft_free_data();

void		ft_def_flag(char *format, t_arg **argument, va_list *arg);
void		ft_def_size(char *format, t_arg **argument, va_list *arg);
void		ft_def_type(char *format, va_list *arg, t_arg **argument, t_list **li);

void		ft_convert_char(t_arg **argument, va_list *arg);
void		ft_convert_str(t_arg **argument, va_list *arg);
void		ft_convert_ptr(t_arg **argument, va_list *arg);
void		ft_convert_hexa(t_arg **argument, va_list *arg);
void		ft_convert_unsigned(t_arg **argument, va_list *arg);
void		ft_convert_int(t_arg **argument, va_list *arg);
void		ft_convert_pcent(t_arg **argument, va_list *arg);

void		ft_appli_flag(t_arg **argument, t_list **li);
void        apply_preci(t_arg **argument, t_list **cur, int len, int len_elem);
void        apply_moin(t_arg **argument, t_list **cur, int len, int len_elem);
void        apply_zero(t_arg **argument, t_list **cur, int len, int len_elem);
void        apply_size(t_arg **argument, t_list **cur, int len, int len_elem);

#endif
