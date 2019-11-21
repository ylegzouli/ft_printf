/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:13:15 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 17:16:55 by ylegzoul         ###   ########.fr       */
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
	if (!(li = ft_lstnew(NULL)))
		return (0);
	if (!(ft_start_printf(format, &arg, &li)))
		return (0);
	va_end(arg);
	ft_print_lst_char(li);
	ret = ft_lstsize(li) - 1;
//	ft_lstclear(&li, &free);
	return (ret);
}

int			ft_start_printf(const char *format, va_list *arg, t_list **li)
{
	t_arg		*data;
	char		*next_arg;
	
	next_arg = ft_strchr(format, '%');
	if (next_arg == NULL)
	{
		if (!(ft_tab_to_lst((li), (char *)format, ft_strlen(format))))
			return (0);
	}
	else if (next_arg > format)
	{
		if (!(ft_tab_to_lst(li, (char *)format, (next_arg - format))))
			return (0);
		if (!(ft_start_printf(next_arg, arg, li)))
			return (0);
	}
	else
		if (!(ft_start_opt(next_arg, arg, li, &data)))
			return (0);
	return (1);
}

int		ft_start_opt(char *next_arg, va_list *arg, t_list **li, t_arg **data)
{
		if (!(ft_init_data(data)))
			return (0);
		ft_def_flag(next_arg, data, arg);
		ft_def_size((*data)->current, data, arg);
		ft_def_preci((*data)->current, data, arg);
		ft_def_type((*data)->current, arg, data, li);
		if (!(ft_convert(data, arg)))
			return (0);
		if (!(ft_appli(data, li)))
			return (0);
		next_arg = (*data)->current + 1;
		if (!(ft_start_printf(next_arg, arg, li)))
			return (0);
		return (1);
}

int		ft_init_data(t_arg **data)
{
	int		i;

	i = 0;
	if (!((*data) = malloc(sizeof(t_arg))))
			return (0);
	(*data)->size = -1;
	(*data)->type = '\0';
	if (!((*data)->elem = ft_lstnew(NULL)))
		return (0);
	(*data)->precision = -1;
	while (i < (NB_FLAG))
	{
		((*data)->flags)[i] = '\0';
		i++;
	}
	((*data)->flags)[i] = '\0';
	(*data)->espace = ' ';
	(*data)->zero = '0';
	(*data)->moin = '-';
	((*data)->str_null)[0] = '(';
	((*data)->str_null)[1] = 'n';
	((*data)->str_null)[2] = 'u';
	((*data)->str_null)[3] = 'l';
	((*data)->str_null)[4] = 'l';
	((*data)->str_null)[5] = ')';
	((*data)->str_null)[6] = '\0';
	return (1);
}

void		ft_free_data()
{
}
