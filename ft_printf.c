/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:15 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/14 14:54:18 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	t_list	*li;
	int		ret;	

	ret = 0;
	if (format == '\0')
		return (0);
	li = ft_lstnew(NULL);
	va_start(arg, format);
	ft_start_printf(format, &arg, &li);
	va_end(arg);
	ft_print_lst_char(li);
	ret = ft_lstsize(li);
	return (ret);
}

void		ft_start_printf(const char *format, va_list *arg, t_list **li)
{
	t_arg		*argument;
	char		*next_arg;
	int			i;
	
	next_arg = ft_strchr(format, '%');
	i = 0;
	if (next_arg == NULL)
		ft_tab_to_lst((li), (char *)format, ft_strlen(format));
	else if (next_arg > format)
	{
		ft_tab_to_lst(li, (char *)format, (next_arg - format));
		ft_start_printf(next_arg, arg, li);
	}
	else
	{
		if (!(argument = malloc(sizeof(t_arg))))
			return ;
		ft_init_data(&argument);
		ft_def_flag(next_arg, &argument);
		ft_def_indice_arg(&argument);
		ft_def_size(next_arg, &argument);
		ft_def_type(next_arg, arg, &argument, li);
		ft_appli_flag(&argument, li);
		next_arg = &(next_arg[argument->size_opt]);
		ft_start_printf(next_arg, arg, li);
	}
}

void		ft_init_data(t_arg **argument)
{
	int		i;

	i = 0;
	(*argument)->indice_arg = 0;
	(*argument)->size = -1;
	(*argument)->type = '\0';
	(*argument)->elem = NULL;
	while (i < (NB_FLAG))
	{
		((*argument)->flags)[i] = '\0';
		i++;
	}
	((*argument)->flags)[i] = '\0';

	(*argument)->size_opt = 0;
	return ;
}

void		ft_free_data()
{
}
