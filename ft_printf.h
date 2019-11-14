/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:12 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/13 17:19:16 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FLAG "-0.*"
# define TYPE "cspdiuxX%"

# define NB_FLAG 4

typedef struct	s_arg
{
	char	flags[NB_FLAG + 1];
	int		indice_arg;
	int		size;
	char	type;


	char	*elem;
	int		size_opt;

}				t_arg;

int         ft_printf(const char *format, ...);
void		ft_start_printf(const char *format, va_list *arg, t_list **li);
void		ft_init_data(t_arg **argument);
void		ft_free_data();

void		ft_def_flag(char *format, t_arg **argument);
void		ft_def_indice_arg(t_arg **argument);
void		ft_def_size(char *format, t_arg **argument);
void		ft_def_type(char *format, va_list *arg, t_arg **argument, t_list **li);

void		ft_convert_char(t_arg **argument, va_list *arg);
void		ft_convert_str(t_arg **argument, va_list *arg);
void		ft_convert_ptr(t_arg **argument, va_list *arg);
void		ft_convert_hexa(t_arg **argument, va_list *arg);
void		ft_convert_unsigned(t_arg **argument, va_list *arg);
void		ft_convert_int(t_arg **argument, va_list *arg);
void		ft_convert_pcent(t_arg **argument, va_list *arg);

void		ft_appli_flag(t_arg **argument, t_list **li);

#endif
