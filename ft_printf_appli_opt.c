/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft_appliflag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:19:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/17 14:55:20 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_appli(t_arg **data, t_list **li)
{
	int		len;
	int		len_elem;
	t_list	*cur;
 
 	cur = (*data)->elem->next;
	free((*data)->elem);
 	len_elem = ft_lstsize(cur);
 	if ((*data)->size > len_elem)
        len = (*data)->size;
    else
        len = len_elem;
	if ((*data)->precision >= 0 && (*data)->type == 's')
	{	
		ft_appli_preci(data, &cur, len, len_elem);
		len_elem = (*data)->precision;
	}
	if (ft_strchr((*data)->flags, '-') != NULL)
		ft_appli_moin(data, &cur, len, len_elem);
	else if (ft_strchr((*data)->flags, '0') != NULL)	
		ft_appli_zero(data, &cur, len, len_elem);
	else
		ft_appli_size(data, &cur, len, len_elem);
	(*data)->elem = cur;
	ft_lstadd_back(li, (*data)->elem);
}

void		ft_appli_preci(t_arg **data, t_list **cur, int len, int len_elem)
{
	int		i;
	t_list	*lst_tmp;

	i = 0;
	if (len_elem > (*data)->precision)
	{
		lst_tmp = (*cur);
		while (i < (*data)->precision)
		{	
			(*cur) = (*cur)->next;
			i++;
		}
		ft_lstclear(cur, &free);
		(*cur) = lst_tmp;
		i = 0;
		while (i < (*data)->precision - 1)
		{
			(*cur) = (*cur)->next;
			i++;
		}
		(*cur)->next = NULL;
		(*cur) = lst_tmp;	
	}
}

void		ft_appli_moin(t_arg **data, t_list **cur, int len, int len_elem)
{
	while (len_elem < len)
	{
		ft_lstadd_back(cur, ft_lstnew(&((*data)->espace)));
		len_elem++;
	}
}

void		ft_appli_zero(t_arg **data, t_list **cur, int len, int len_elem)
{
	char	*tmp;
	t_list	*lst_tmp;

	tmp = (*cur)->content;
	lst_tmp = (*cur);
	if ((*data)->type == 'i' || (*data)->type == 'd')
	{
		if (tmp[0] == '-')
			(*cur) = (*cur)->next;
	}
	while (len_elem < len)
	{
		ft_lstadd_front(cur, ft_lstnew(&(*data)->zero));
		len_elem++;
	}
	if (tmp[0] == '-')
	{
		lst_tmp->next = *cur;
		(*cur) = lst_tmp;
	}
}

void		ft_appli_size(t_arg **data, t_list **cur, int len, int len_elem)
{
	while (len_elem < len)
    {
		ft_lstadd_front(cur, ft_lstnew(&(*data)->espace));
        len_elem++;
    }
}
