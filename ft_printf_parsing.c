/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:52 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/13 17:49:03 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_is_type(char c)
{
	int		i;

	i = 0;
	while (TYPE[i])
	{
		if (c == TYPE[i])
			return (TYPE[i]);
		i++;
	}
	return ('\0');
}

static char		ft_is_flag(char c)
{
	int		i;

	i = 0;
	while (FLAG[i])
	{
		if (c == FLAG[i])
			return (FLAG[i]);
		i++;
	}
	return ('\0');
}

void        ft_def_flag(char *format, t_arg **argument)
{
	int		i;

	i = 1;
	while (!ft_is_type(format[i]) && !(format[i] >= 49 && format[i] <= 57))
	{
		if (ft_is_flag(format[i]))
			(*argument)->flags[i - 1] = ft_is_flag(format[i]);
		i++;
	}
	return ;
}
/*
void		ft_def_indice_arg(t_arg **argument)
{
	int		i;
	int		ret;

	i = 0;
	while (i < (NB_FLAG + 1))
	{
		if ((*argument)->flags[i] == '*')
			ret++;
		i++;
	}
	(*argument)->indice_arg = ret;
	return ;
}                                                       ---------------> cas FLAG '%*' ?   */


void        ft_def_size(char *format, t_arg **argument)
{	
	int		i;
	int		ret;
	int		tmp;
	
	i = 1;
	ret = 0;
	while (ft_is_flag(format[i] && format[i]))
		i++;
	while (ft_isdigit(format[i]) && format[i])
	{
		tmp = (int)format[i] - 48;
		ret = ret * 10 + tmp;
		i++;
	}
	(*argument)->size = ret;
	return ;
}

void		ft_def_type(char *format, va_list *arg, t_arg **argument, t_list **li)
{
	int		i;

	i = 1;
	while ((ft_is_flag(format[i]) || ft_isdigit(format[i])) && format)
		i++;
	(*argument)->size_opt = i + 1;
	if (format[i])
		(*argument)->type = ft_is_type(format[i]);
	if ((*argument)->type == 'd' || (*argument)->type == 'i')
		ft_convert_int(argument, arg);
	else if ((*argument)->type == 's')
		ft_convert_str(argument, arg);
	else if ((*argument)->type == 'c')
		ft_convert_char(argument, arg);
/*	else if ((*argument)->type == '%')
		ft_convert_char(argument, arg);
	else if ((*argument)->type == 'p')
	else if ((*argument)->type == 'u')	
	else if ((*argument)->type == 'x' || (*argument)->type == 'X') */
	else
		return ;
}
