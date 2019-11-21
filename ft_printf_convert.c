/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:42:16 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 18:38:43 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_convert(t_arg **data, va_list *arg)
{
	if ((*data)->type == 'd' || (*data)->type == 'i')
	{
		if (!(ft_convert_int(data, arg)))
			return (0);
	}
	else if ((*data)->type == 's' && !(ft_convert_str(data, arg)))
		return (0);
	else if ((*data)->type == 'c' && !(ft_convert_char(data, arg)))
		return (0);
	else if ((*data)->type == 'x' || (*data)->type == 'X')
	{
		if (!(ft_convert_hexa(data, arg)))
			return (0);
	}
	else if ((*data)->type == 'u' && !(ft_convert_unsigned(data, arg)))
		return (0);
	else if ((*data)->type == 'p' && !(ft_convert_ptr(data, arg)))
		return (0);
	else if ((*data)->type == '%' && !(ft_convert_pcent(data, arg)))
		return (0);
	else
		return (1);
	return (1);
}

int				ft_convert_str(t_arg **data, va_list *arg)
{
	char	*str;
	t_list	*cur;

	str = va_arg(*arg, char *);
	if (str == NULL)
	{
		if (!(ft_putstr_lst((*data)->str_null, &((*data)->elem))))
			return (0);
	}
	else
	{
		if (!(ft_putstr_lst(str, &((*data)->elem))))
			return (0);
	}
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
	return (1);
}

int				ft_convert_char(t_arg **data, va_list *arg)
{
	char	c;
	t_list	*cur;

	c = va_arg(*arg, int);
	if (!(ft_putchar_lst(c, &((*data)->elem))))
		return (0);
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
	return (1);
}

int				ft_convert_ptr(t_arg **data, va_list *arg)
{
	void			*temp;
	unsigned long	ptr;
	char			tmp;
	t_list			*cur;
	t_list			*tmp_lst;

	temp = va_arg(*arg, void *);
	ptr = (unsigned long)temp;
	if (!(ft_pnblul(ptr, 16, "0123456789abcdef", &((*data)->elem))))
		return (0);
	cur = (*data)->elem;
	tmp_lst = (*data)->elem;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
		(*data)->elem = (*data)->elem->next;
	}
	cur->next = NULL;
	(*data)->elem = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = tmp_lst;
	tmp = 'x';
	ft_lstadd_front(&((*data)->elem), ft_lstnew_malloc(&tmp, 1));
	ft_lstadd_front(&((*data)->elem), ft_lstnew_malloc(&((*data)->zero), 1));
	return (1);
}

int				ft_convert_hexa(t_arg **data, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;
	t_list			*tmp;

	n = va_arg(*arg, unsigned int);
	if ((*data)->type == 'x')
		if (!(ft_pnblu(n, 16, "0123456789abcdef", &((*data)->elem))))
			return (0);
	if ((*data)->type == 'X')
		if (!(ft_pnblu(n, 16, "0123456789ABCDEF", &((*data)->elem))))
			return (0);
	cur = (*data)->elem;
	tmp = (*data)->elem;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
		(*data)->elem = (*data)->elem->next;
	}
	cur->next = NULL;
	(*data)->elem = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = tmp;
	return (1);
}

int				ft_convert_unsigned(t_arg **data, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;

	n = va_arg(*arg, unsigned int);
	if (!(ft_putnbr_lst_u(n, &((*data)->elem))))
		return (0);
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
	return (1);
}

int				ft_convert_int(t_arg **data, va_list *arg)
{
	int		n;
	t_list	*cur;

	n = va_arg(*arg, int);
	if (!(ft_putnbr_lst(n, &((*data)->elem))))
		return (0);
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
	return (1);
}

int				ft_convert_pcent(t_arg **data, va_list *arg)
{
	t_list	*cur;

	if (!(ft_putchar_lst('%', &((*data)->elem))))
		return (0);
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
	return (1);
}
