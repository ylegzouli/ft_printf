/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:42:16 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/18 17:45:57 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_convert(t_arg **data, va_list *arg)
{
	if ((*data)->type == 'd' || (*data)->type == 'i')
		ft_convert_int(data, arg);
	else if ((*data)->type == 's')
		ft_convert_str(data, arg);
	else if ((*data)->type == 'c')
		ft_convert_char(data, arg);
	else if ((*data)->type == 'x' || (*data)->type == 'X')
		ft_convert_hexa(data, arg);
	else if ((*data)->type == 'u')
		ft_convert_unsigned(data, arg);
	else if ((*data)->type == 'p')
		ft_convert_ptr(data, arg);
	else if ((*data)->type == '%')
		ft_convert_pcent(data, arg);
	else
		return ;
}

void		ft_convert_str(t_arg **data, va_list *arg)
{
	char	*str;
	t_list	*cur;
	
	str = va_arg(*arg, char *);
	ft_putstr_lst(str, &((*data)->elem));
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
}

void		ft_convert_char(t_arg **data, va_list *arg)
{
	char	c;
	t_list	*cur;

	c = va_arg(*arg, int);
	ft_putchar_lst(c, &((*data)->elem));
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
}

void        ft_convert_ptr(t_arg **data, va_list *arg)
{
	void			*temp;
	unsigned long  	ptr;
	char			tmp;
	t_list			*cur;
	t_list			*tmp_lst;

	temp = va_arg(*arg, void *);
	ptr = (unsigned long)temp;
	ft_putnbr_base_lst_ul(ptr, 16, "0123456789abcdef", &((*data)->elem));
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
	tmp = '0';
	ft_lstadd_front(&((*data)->elem), ft_lstnew_malloc(&tmp, 1));
}

void        ft_convert_hexa(t_arg **data, va_list *arg)
{
	unsigned int n;
	t_list		*cur;
	t_list		*tmp;

	n = va_arg(*arg, unsigned int);

	if ((*data)->type == 'x')
		ft_putnbr_base_lst_u(n, 16, "0123456789abcdef", &((*data)->elem));
	if ((*data)->type == 'X')
		ft_putnbr_base_lst_u(n, 16, "0123456789ABCDEF", &((*data)->elem));
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
}

void        ft_convert_unsigned(t_arg **data, va_list *arg)
{
	unsigned int n;
	t_list		*cur;
		
	n = va_arg(*arg, unsigned int);
	ft_putnbr_lst_u(n, &((*data)->elem));
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
}

void        ft_convert_int(t_arg **data, va_list *arg)
{
	int		n;
	t_list	*cur;

	n = va_arg(*arg, int);
	ft_putnbr_lst(n, &((*data)->elem));
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
}

void        ft_convert_pcent(t_arg **data, va_list *arg)
{
	t_list	*cur;

	ft_putchar_lst('%', &((*data)->elem));
	cur = (*data)->elem->next;
	free((*data)->elem);
	(*data)->elem = cur;
}
