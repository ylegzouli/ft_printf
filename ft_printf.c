/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:15 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/18 18:28:44 by ylegzoul         ###   ########.fr       */
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
	va_start(arg, format);
	li = ft_lstnew(NULL);
	ft_start_printf(format, &arg, &li);
	va_end(arg);
	ft_print_lst_char(li);
	ret = ft_lstsize(li) - 1;
//	ft_lstclear(&li, &free);
	return (ret);
}

void		ft_start_printf(const char *format, va_list *arg, t_list **li)
{
	t_arg		*data;
	char		*next_arg;
	
	next_arg = ft_strchr(format, '%');
	if (next_arg == NULL)
		ft_tab_to_lst((li), (char *)format, ft_strlen(format));
	else if (next_arg > format)
	{
		ft_tab_to_lst(li, (char *)format, (next_arg - format));
		ft_start_printf(next_arg, arg, li);
	}
	else
	{
		ft_init_data(&data);
		ft_def_flag(next_arg, &data, arg);
		ft_def_size(data->current, &data, arg);
		ft_def_type(data->current, arg, &data, li);
		ft_convert(&data, arg);
		ft_appli(&data, li);
		next_arg = data->current + 1;
		ft_start_printf(next_arg, arg, li);
	}
}

void		ft_init_data(t_arg **data)
{
	int		i;

	i = 0;
	if (!((*data) = malloc(sizeof(t_arg))))
			return ;
	(*data)->size = -1;
	(*data)->type = '\0';
	(*data)->elem = ft_lstnew(NULL);
	(*data)->precision = -1;
	while (i < (NB_FLAG))
	{
		((*data)->flags)[i] = '\0';
		i++;
	}
	((*data)->flags)[i] = '\0';
	(*data)->espace = ' ';
	(*data)->zero = '0';

	return ;
}

void		ft_free_data()
{
}
