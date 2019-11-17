/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_applyflag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:19:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/17 14:55:20 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_appli_flag(t_arg **argument, t_list **li)
{
	int		len;
	int		len_elem;
	t_list	*cur;
 
 	cur = (*argument)->elem->next;
	free((*argument)->elem);
 	len_elem = ft_lstsize(cur);
 	if ((*argument)->size > len_elem)
        len = (*argument)->size;
    else
        len = len_elem;
	if ((*argument)->precision >= 0 && (*argument)->type == 's')
	{	
		apply_preci(argument, &cur, len, len_elem);
		len_elem = (*argument)->precision;
	}
	if (ft_strchr((*argument)->flags, '-') != NULL)
		apply_moin(argument, &cur, len, len_elem);
	else if (ft_strchr((*argument)->flags, '0') != NULL)	
		apply_zero(argument, &cur, len, len_elem);
	else
		apply_size(argument, &cur, len, len_elem);
//	else if(ft_strchr((*argument)->flags, '.') != NULL)	
	(*argument)->elem = cur;
	ft_lstadd_back(li, (*argument)->elem);
}

void		apply_preci(t_arg **argument, t_list **cur, int len, int len_elem)
{
	int		i;
	t_list	*lst_tmp;

	i = 0;
	if (len_elem > (*argument)->precision)
	{
		lst_tmp = (*cur);
		while (i < (*argument)->precision)
		{	
			(*cur) = (*cur)->next;
			i++;
		}
		ft_lstclear(cur, &free);
		(*cur) = lst_tmp;
		i = 0;
		while (i < (*argument)->precision - 1)
		{
			(*cur) = (*cur)->next;
			i++;
		}
		(*cur)->next = NULL;
		(*cur) = lst_tmp;	
	}
}

void		apply_moin(t_arg **argument, t_list **cur, int len, int len_elem)
{
	while (len_elem < len)
	{
		ft_lstadd_back(cur, ft_lstnew(&((*argument)->espace)));
		len_elem++;
	}
}

void		apply_zero(t_arg **argument, t_list **cur, int len, int len_elem)
{
	char	*tmp;
	t_list	*lst_tmp;

	tmp = (*cur)->content;
	lst_tmp = (*cur);
	if ((*argument)->type == 'i' || (*argument)->type == 'd')
	{
		if (tmp[0] == '-')
			(*cur) = (*cur)->next;
	}
	while (len_elem < len)
	{
		ft_lstadd_front(cur, ft_lstnew(&(*argument)->zero));
		len_elem++;
	}
	if (tmp[0] == '-')
	{
		lst_tmp->next = *cur;
		(*cur) = lst_tmp;
	}
}

void		apply_size(t_arg **argument, t_list **cur, int len, int len_elem)
{
	while (len_elem < len)
    {
		ft_lstadd_front(cur, ft_lstnew(&(*argument)->espace));
        len_elem++;
    }
}
