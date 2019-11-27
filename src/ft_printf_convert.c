/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:04:18 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/25 19:30:29 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_convert(t_arg **d, va_list *arg)
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

int				ft_convert_str(t_arg **d, va_list *arg)
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
		//printf("size:%d\ncurrent:%s\nflag:%s\ntype:%c\nprec:%d\nptrnull:%d\nsizenull:%d\n", (*d)->size, (*d)->current, (*d)->fl, (*d)->type, (*d)->prec, (*d)->ptrnull, (*d)->sizenull);
	}
//	ft_print_lst_char((*d)->elem);
//	printf("\n");
	return (1);
}

int				ft_convert_char(t_arg **d, va_list *arg)
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

int				ft_convert_ptr(t_arg **d, va_list *arg)
{
	void			*temp;
	unsigned long	ptr;
	char			tmp;
	t_list			*cur;
	t_list			*tmp_lst;

	temp = va_arg(*arg, void *);
	if (temp != NULL)
	{
		ptr = (unsigned long)temp;
		if (!(ft_pnblul(ptr, 16, "0123456789abcdef", &((*d)->elem))))
			return (0);
		cur = (*d)->elem;
		tmp_lst = (*d)->elem;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
			(*d)->elem = (*d)->elem->next;
		}
		cur->next = NULL;
		(*d)->elem = (*d)->elem->next;
		free((*d)->elem);
		(*d)->elem = tmp_lst;
	}
	else if ((*d)->prec != 0)
	{
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
		if (!(ft_putchar_lst('0', &((*d)->elem))))
			return (0);
	}
	else if ((*d)->prec == 0)
	{
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
	}
	tmp = 'x';
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&tmp, 1));
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&((*d)->zero), 1));
	return (1);
}
