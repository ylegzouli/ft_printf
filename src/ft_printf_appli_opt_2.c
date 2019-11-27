/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_appli_opt_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:27:23 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/27 20:51:17 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_appli_preci_pid(t_arg **d, t_list **cur, char **tmp, int len_e)
{
	if (len_e <= (*d)->prec && (*d)->type != 's')
	{
		if ((*d)->type == 'i' || (*d)->type == 'd')
		{
			if ((*d)->ptrnull == 0 && *tmp[0] == '-')
			{
				(*cur) = (*cur)->next;
				((*d)->prec)++;
				*tmp[0] = '&';
			}
		}
		if ((*d)->type == 'p')
		{
			(*cur) = (*cur)->next->next;
			*tmp[0] = 'x';
			(*d)->prec = (*d)->prec + 2;
		}
	}
}

void	ft_appli_preci_str(t_arg **d, t_list **cur, int len, int len_e)
{
	int		i;
	t_list	*lst_tmp;

	i = 0;
	if (len_e > (*d)->prec && (*d)->type == 's')
	{
		lst_tmp = (*cur);
		while (i++ < (*d)->prec)
			(*cur) = (*cur)->next;
		ft_lstclear(cur, &free);
		if ((*d)->prec == 0)
		{
			(*cur) = ft_lstnew(NULL);
			(*d)->sizenull++;
			return ;
		}
		(*cur) = lst_tmp;
		i = 0;
		while (i++ < (*d)->prec - 1)
			(*cur) = (*cur)->next;
		(*cur)->next = NULL;
		(*cur) = lst_tmp;
	}
}

int		ft_size(t_arg **d, int *len, int *len_e, t_list **cur)
{
	(*cur) = (*d)->elem;
	ft_size_2(d, len, len_e, cur);
	if (((*d)->prec >= *len_e && (*d)->type != 's') || (*d)->type == 's')
	{
		if ((*d)->prec >= 0)
		{
			if (!(ft_appli_preci(d, cur, *len, *len_e)))
				return (0);
			if ((*d)->type != 's')
				*len_e = (*d)->prec;
			else if (*len_e > (*d)->prec)
				*len_e = (*d)->prec;
		}
	}
	if (ft_strchr((*d)->fl, '-') != NULL)
	{
		if (!(ft_appli_moin(d, cur, *len, *len_e)))
			return (0);
	}
	return (1);
}

void	ft_size_2(t_arg **d, int *len, int *len_e, t_list **cur)
{
	if ((*d)->ptrnull != 0 && (*d)->type != 'p' && (*d)->prec != 0)
		*len_e = 1;
	else if ((*d)->ptrnull != 0 && (*d)->type == 'p')
	{
		*len_e = ft_lstsize(*cur) - ((*d)->sizenull);
	}
	else
	{
		*len_e = ft_lstsize(*cur);
		if (ft_strchr((*d)->fl, '0') == 0)
			*len_e = *len_e - (*d)->ptrnull;
	}
	if ((*d)->size > *len_e)
	{
		*len = (*d)->size;
	}
	else
		*len = *len_e;
}

int		ft_appli_size(t_arg **d, t_list **cur, int len, int len_e)
{
	t_list	*tmp;

	while (len_e < len && (*d)->prec < (*d)->size && (*d)->type != 's')
	{
		if (!(tmp = ft_lstnew_malloc(&(*d)->espace, 1)))
			return (0);
		ft_lstadd_front(cur, tmp);
		len_e++;
	}
	while (len_e < (*d)->size && (*d)->type == 's')
	{
		if (!(tmp = ft_lstnew_malloc(&(*d)->espace, 1)))
			return (0);
		ft_lstadd_front(cur, tmp);
		len_e++;
		((*d)->prec)++;
	}
	return (1);
}
