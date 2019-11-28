/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:04:18 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/27 20:08:34 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_convert(t_arg **d, va_list *arg)
{
	if ((*d)->type == 'd' || (*d)->type == 'i')
	{
		if (!(ft_convert_int(d, arg)))
			return (0);
	}
	else if ((*d)->type == 's' && !(ft_convert_str(d, arg)))
		return (0);
	else if ((*d)->type == 'c' && !(ft_convert_char(d, arg)))
		return (0);
	else if ((*d)->type == 'x' || (*d)->type == 'X')
	{
		if (!(ft_convert_hexa(d, arg)))
			return (0);
	}
	else if ((*d)->type == 'u' && !(ft_convert_unsigned(d, arg)))
		return (0);
	else if ((*d)->type == 'p' && !(ft_convert_ptr(d, arg)))
		return (0);
	else if ((*d)->type == '%' && !(ft_convert_pcent(d, arg)))
		return (0);
	else
		return (1);
	return (1);
}

int		ft_convert_str(t_arg **d, va_list *arg)
{
	char	*str;
	t_list	*cur;

	str = va_arg(*arg, char *);
	if ((*d)->prec != 0)
	{
		if (str == NULL)
		{
			if (!(ft_putstr_lst((*d)->str_null, &((*d)->elem))))
				return (0);
		}
		else
		{
			if (!(ft_putstr_lst(str, &((*d)->elem))))
				return (0);
		}
		cur = (*d)->elem->next;
		free((*d)->elem);
		(*d)->elem = cur;
	}
	return (1);
}

int		ft_convert_char(t_arg **d, va_list *arg)
{
	char	c;
	t_list	*cur;

	c = va_arg(*arg, int);
	if (!(ft_putchar_lst(c, &((*d)->elem))))
		return (0);
	cur = (*d)->elem->next;
	free((*d)->elem);
	(*d)->elem = cur;
	return (1);
}

int		ft_convert_ptr(t_arg **d, va_list *arg)
{
	void			*temp;
	t_list			*cur;
	t_list			*tmp_lst;

	temp = va_arg(*arg, void *);
	if (!(ptr_2(d, &cur, &tmp_lst, temp)))
		return (0);
	if ((*d)->prec != 0 && temp == NULL)
	{
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
		if (!(ft_putchar_lst('0', &((*d)->elem))))
			return (0);
	}
	else if ((*d)->prec == 0)
	{
		if (temp == NULL)
			(*d)->ptrnull = 1;
		else if (temp != NULL)
			(*d)->ptrnull = 2;
		((*d)->sizenull)++;
	}
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&((*d)->x), 1));
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&((*d)->zero), 1));
	return (1);
}

int		ptr_2(t_arg **d, t_list **cur, t_list **tmp_lst, void *temp)
{
	unsigned long	ptr;

	if (temp != NULL)
	{
		ptr = (unsigned long)temp;
		if (!(ft_pnblul(ptr, 16, "0123456789abcdef", &((*d)->elem))))
			return (0);
		(*cur) = (*d)->elem;
		(*tmp_lst) = (*d)->elem;
		while ((*cur)->next->next != NULL)
		{
			(*cur) = (*cur)->next;
			(*d)->elem = (*d)->elem->next;
		}
		(*cur)->next = NULL;
		(*d)->elem = (*d)->elem->next;
		free((*d)->elem);
		(*d)->elem = *tmp_lst;
	}
	return (1);
}
