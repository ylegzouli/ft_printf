/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:42:16 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/16 17:24:38 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_convert_str(t_arg **argument, va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	ft_putstr_lst(str, &((*argument)->elem));
}

void		ft_convert_char(t_arg **argument, va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	ft_putchar_lst(c, &((*argument)->elem));
}

void        ft_convert_ptr(t_arg **argument, va_list *arg)
{
	void			*temp;
	unsigned long  	ptr;
	char			tmp;

	temp = va_arg(*arg, void *);
	ptr = (unsigned long)temp;
	ft_putnbr_base_lst_ul(ptr, 16, "0123456789abcdef", &((*argument)->elem));
	tmp = 'x';
	ft_lstadd_front(&((*argument)->elem), ft_lstnew_malloc(&tmp, 1));
	ft_lstadd_front(&((*argument)->elem), ft_lstnew_malloc((*argument)->zero, 1));
}

void        ft_convert_hexa(t_arg **argument, va_list *arg)
{
	unsigned int n;

	n = va_arg(*arg, unsigned int);

	if ((*argument)->type == 'x')
		ft_putnbr_base_lst_u(n, 16, "0123456789abcdef", &((*argument)->elem));
	if ((*argument)->type == 'X')
		ft_putnbr_base_lst_u(n, 16, "0123456789ABCDEF", &((*argument)->elem));
}

void        ft_convert_unsigned(t_arg **argument, va_list *arg)
{
	unsigned int n;
	
	n = va_arg(*arg, unsigned int);
	ft_putnbr_lst_u(n, &((*argument)->elem));
}

void        ft_convert_int(t_arg **argument, va_list *arg)
{
	int		n;

	n = va_arg(*arg, int);
	ft_putnbr_lst(n, &((*argument)->elem));
}

void        ft_convert_pcent(t_arg **argument, va_list *arg)
{
	ft_putchar_lst('%', &((*argument)->elem));
}
