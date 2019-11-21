/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ft_appliflag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:19:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 18:38:33 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void		ft_size(t_arg **data, int len, int len_elem, t_list **cur)
{
	if ((*data)->type != 'p' && (*data)->type != 'x' && (*data)->type != 'X')
    {
        *cur = (*data)->elem->next;
        free((*data)->elem);
        len_elem = ft_lstsize(*cur);
    }
    else
    {
        *cur = (*data)->elem;
        len_elem = ft_lstsize(*cur);
    }
    if ((*data)->size > len_elem)
        len = (*data)->size;
    else
        len = len_elem;
} */

int			ft_appli(t_arg **data, t_list **li)
{
	int		len;
	int		len_elem;
	t_list	*cur;
	
	cur = (*data)->elem;
 	len_elem = ft_lstsize(cur);
	if ((*data)->size > len_elem)
        len = (*data)->size;
    else
        len = len_elem;
	if ((*data)->precision >= 0)
	{	
		if (!(ft_appli_preci(data, &cur, len, len_elem)))
			return (0);
		if ((*data)->type != 's')
			len_elem = (*data)->precision;
		else if (len_elem > (*data)->precision)
			len_elem = (*data)->precision;
	}
	if (ft_strchr((*data)->flags, '-') != NULL)
	{
		if (!(ft_appli_moin(data, &cur, len, len_elem)))
			return (0);
	}
	else if (ft_strchr((*data)->flags, '0') != NULL)	
	{	
		if (!(ft_appli_zero(data, &cur, len, len_elem)))
			return (0);
		if ((*data)->precision == -1)
			len = -10;
	}
	if (ft_strchr((*data)->flags, '-') == NULL)
	{	
		if (!(ft_appli_size(data, &cur, len, len_elem)))
			return (0);
		len_elem = (*data)->size;
	}
	(*data)->elem = cur;
	ft_lstadd_back(li, (*data)->elem);
	return (1);
}

int			ft_appli_preci(t_arg **data, t_list **cur, int len, int len_elem)
{
	int		i;
	t_list	*lst_tmp;
	char	*tmp;

	i = 0;
	tmp = (*cur)->content;
	if (len_elem > (*data)->precision && (*data)->type == 's')
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
	if (len_elem < (*data)->precision && (*data)->type != 's')
	{
		if ((*data)->type == 'i' || (*data)->type == 'd')
		{
        	if (tmp[0] == '-')
			{
            	(*cur) = (*cur)->next;
				((*data)->precision)++;
				tmp[0] = '&';
    		}
		}
		if ((*data)->type == 'p')
		{
			(*cur) = (*cur)->next->next;
			tmp[0] = 'x';
			(*data)->precision = (*data)->precision + 2;
		}
		while (len_elem < (*data)->precision)
		{
			ft_lstadd_front(cur, ft_lstnew(&((*data)->zero)));
			len_elem++;
		}
		if (tmp[0] == '&' && ((*data)->type == 'd' || (*data)->type == 'i'))
			ft_lstadd_front(cur, ft_lstnew_malloc(&((*data)->moin), 1));
		if (tmp[0] == 'x' && (*data)->type == 'p')
		{
			ft_lstadd_front(cur, ft_lstnew_malloc(&tmp[0], 1));
			ft_lstadd_front(cur, ft_lstnew(&(*data)->zero));
		}
	}
	return (1);
}

int			ft_appli_moin(t_arg **data, t_list **cur, int len, int len_elem)
{
	t_list		*tmp;

	while (len_elem < len)
	{
		if (!(tmp = ft_lstnew(&((*data)->espace))))
			return (0);
		ft_lstadd_back(cur, tmp);
		len_elem++;
	}
	return (1);
}

int			ft_appli_zero(t_arg **data, t_list **cur, int len, int len_elem)
{
	char	*tmp;
	t_list	*lst_tmp;
	t_list	*temp;

	tmp = (*cur)->content;
	lst_tmp = (*cur);
	if ((*data)->type == 'i' || (*data)->type == 'd')
	{
		if (tmp[0] == '-')
			(*cur) = (*cur)->next;
	}
	while (len_elem < len && (*data)->precision < 0)
	{
		if (!(temp = ft_lstnew(&(*data)->zero)))
			return (0);
		ft_lstadd_front(cur, temp);
		len_elem++;
	}
	if (tmp[0] == '-')
	{
		lst_tmp->next = *cur;
		(*cur) = lst_tmp;
	}
	return (1);
}

int			ft_appli_size(t_arg **data, t_list **cur, int len, int len_elem)
{
	t_list	*tmp;

	if ((*data)->precision == 1 && (*data)->type != 's')
		len_elem = len_elem + 2;
	while (len_elem < len && (*data)->precision < (*data)->size && (*data)->type != 's')
    {
		if (!(tmp = ft_lstnew(&(*data)->espace)))
			return (0);
		ft_lstadd_front(cur, tmp);
        len_elem++;
    }
	while (len_elem < (*data)->size && (*data)->type == 's')
	{
		if (!(tmp = ft_lstnew(&(*data)->espace)))
			return (0);	
		ft_lstadd_front(cur, tmp);
		len_elem++;
		((*data)->precision)++;
	}
	return (1);
}
