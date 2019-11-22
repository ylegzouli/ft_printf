/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:03:31 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/22 16:24:26 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_def_flag(char *format, t_arg **d, va_list *arg)
{
	int		i;

	i = 1;
	while (ft_is_flag(format[i]))
	{
		if (ft_strchr((*d)->fl, ft_is_flag(format[i]) == '\0'))
			(*d)->fl[i - 1] = ft_is_flag(format[i]);
		i++;
	}
	if (format[i] == '*')
	{
		(*d)->size = va_arg(*arg, int);
		if ((*d)->size < 0)
		{
			if (ft_strchr((*d)->fl, '-') == NULL)
				(*d)->fl[i - 1] = '-';
			(*d)->size = -((*d)->size);
		}
		i++;
	}
	(*d)->current = &format[i];
	return ;
}

void	ft_def_size(char *format, t_arg **d, va_list *arg)
{
	int		i;
	int		ret;
	int		tmp;

	i = 0;
	ret = 0;
	if ((*d)->size < 0 && ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]) && format[i])
		{
			tmp = (int)format[i] - 48;
			ret = ret * 10 + tmp;
			i++;
		}
		(*d)->size = ret;
	}
	(*d)->current = &format[i];
	return ;
}

void	ft_def_preci(char *format, t_arg **d, va_list *arg)
{
	int		i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
		{
			(*d)->prec = va_arg(*arg, int);
			i++;
		}
		else if (ft_isdigit(format[i]))
		{
			(*d)->prec = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]) && format[i])
				i++;
		}
		else
			(*d)->prec = 0;
		(*d)->current = &format[i];
	}
	return ;
}

void	ft_def_type(char *format, va_list *arg, t_arg **d, t_list **li)
{
	int		i;

	i = 0;
	if (format[i])
		(*d)->type = ft_is_type(format[i]);
	return ;
}
