/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:36:52 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/18 18:28:50 by ylegzoul         ###   ########.fr       */
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

void        ft_def_flag(char *format, t_arg **data, va_list *arg)
{
	int		i;

	i = 1;
	while (ft_is_flag(format[i]))
	{	
		(*data)->flags[i - 1] = ft_is_flag(format[i]);
		i++;
	}
	if (format[i] == '*')
	{	
		(*data)->size = va_arg(*arg, int);
		i++;
	}
	(*data)->current = &format[i];
	return ;
}

void        ft_def_size(char *format, t_arg **data, va_list *arg)
{	
	int		i;
	int		ret;
	int		tmp;
	
	i = 0;
	ret = 0;
	if ((*data)->size < 0)
	{
		while (ft_isdigit(format[i]) && format[i])
		{
			tmp = (int)format[i] - 48;
			ret = ret * 10 + tmp;
			i++;
		}
		(*data)->size = ret;
	}
	if (format[i] == '.')
    {
        i++;
        if (format[i] == '*')
		{
			(*data)->precision = va_arg(*arg, int);
			i++;
		}
        else
		{	
			(*data)->precision = ft_atoi(&format[i]);
    		while (ft_isdigit(format[i]) && format[i])
        		i++;
		}
	}
	(*data)->current = &format[i];
	return ;
}

void		ft_def_type(char *format, va_list *arg, t_arg **data, t_list **li)
{
	int		i;

	i = 0;
	if (format[i])
		(*data)->type = ft_is_type(format[i]);
	return ;
}
