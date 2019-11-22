/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:04:18 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/22 14:04:44 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmp = 'x';
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&tmp, 1));
	ft_lstadd_front(&((*d)->elem), ft_lstnew_malloc(&((*d)->zero), 1));
	return (1);
}

int				ft_convert_hexa(t_arg **d, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;
	t_list			*tmp;

	n = va_arg(*arg, unsigned int);
	if ((*d)->type == 'x')
		if (!(ft_pnblu(n, 16, "0123456789abcdef", &((*d)->elem))))
			return (0);
	if ((*d)->type == 'X')
		if (!(ft_pnblu(n, 16, "0123456789ABCDEF", &((*d)->elem))))
			return (0);
	cur = (*d)->elem;
	tmp = (*d)->elem;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
		(*d)->elem = (*d)->elem->next;
	}
	cur->next = NULL;
	(*d)->elem = (*d)->elem->next;
	free((*d)->elem);
	(*d)->elem = tmp;
	return (1);
}

int				ft_convert_unsigned(t_arg **d, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;

	n = va_arg(*arg, unsigned int);
	if (!(ft_putnbr_lst_u(n, &((*d)->elem))))
		return (0);
	cur = (*d)->elem->next;
	free((*d)->elem);
	(*d)->elem = cur;
	return (1);
}

int				ft_convert_int(t_arg **d, va_list *arg)
{
	int		n;
	t_list	*cur;

	n = va_arg(*arg, int);
	if (!(ft_putnbr_lst(n, &((*d)->elem))))
		return (0);
	cur = (*d)->elem->next;
	free((*d)->elem);
	(*d)->elem = cur;
	return (1);
}

int				ft_convert_pcent(t_arg **d, va_list *arg)
{
	t_list	*cur;

	if (!(ft_putchar_lst('%', &((*d)->elem))))
		return (0);
	cur = (*d)->elem->next;
	free((*d)->elem);
	(*d)->elem = cur;
	return (1);
}
