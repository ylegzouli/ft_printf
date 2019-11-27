/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:25:01 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/25 18:23:29 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_convert_hexa(t_arg **d, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;
	t_list			*tmp;

	n = va_arg(*arg, unsigned int);
	if (n != 0)
	{	
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
	}
	else
	{
		if ((*d)->prec > 0 || (*d)->prec == -9999)
		{
			if (!(ft_putchar_lst('0', &((*d)->elem))))
			return (0);
		}
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
	}
	return (1);
}

int				ft_convert_unsigned(t_arg **d, va_list *arg)
{
	unsigned int	n;
	t_list			*cur;

	n = va_arg(*arg, unsigned int);
	if (n != 0 || (*d)->prec != 0)
	{
		if (!(ft_putnbr_lst_u(n, &((*d)->elem))))
			return (0);
	}
	else
	{
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
		return (1);
	}
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
	if (n != 0 || (*d)->prec > 0)
	{
		if (!(ft_putnbr_lst(n, &((*d)->elem))))
			return (0);
		cur = (*d)->elem->next;
		free((*d)->elem);
		(*d)->elem = cur;
	}
	else
	{
		if ((*d)->prec > 0 || (*d)->prec == -9999)
		{
			if (!(ft_putchar_lst('0', &((*d)->elem))))
				return (0);
		}
		(*d)->ptrnull = 1;
		((*d)->sizenull)++;
	}
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
