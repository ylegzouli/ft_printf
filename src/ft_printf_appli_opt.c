/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_appli_opt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:03:04 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/27 20:40:22 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_appli(t_arg **d, t_list **li)
{
	int		len;
	int		len_e;
	t_list	*cur;

	if (!(ft_size(d, &len, &len_e, &cur)))
		return (0);
	if (ft_strchr((*d)->fl, '0') != NULL && ft_strchr((*d)->fl, '-') == NULL)
	{
		if (!(ft_appli_zero(d, &cur, len, &len_e)))
			return (0);
		if ((*d)->prec == -9999)
			len = -10;
	}
	if (ft_strchr((*d)->fl, '-') == NULL)
	{
		if (!(ft_appli_size(d, &cur, len, len_e)))
			return (0);
		len_e = (*d)->size;
	}
	(*d)->elem = cur;
	if ((*d)->type == 'p' && (*d)->prec == 0 && (*d)->ptrnull == 2)
		(*d)->sizenull--;
	ft_lstadd_back(li, (*d)->elem);
	return (1);
}

int		ft_appli_preci(t_arg **d, t_list **cur, int len, int len_e)
{
	char	*tmp;

	if ((*d)->type != 's')
		tmp = (*cur)->content;
	ft_appli_preci_str(d, cur, len, len_e);
	if (len_e <= (*d)->prec && (*d)->type != 's' && (*d)->type != '%')
	{
		ft_appli_preci_pid(d, cur, &tmp, len_e);
		while (len_e++ < (*d)->prec)
			ft_lstadd_front(cur, ft_lstnew_malloc(&((*d)->zero), 1));
		if ((*d)->ptrnull == 0 || (*d)->type == 'p')
		{
			if (tmp[0] == '&' && ((*d)->type == 'd' || (*d)->type == 'i'))
				ft_lstadd_front(cur, ft_lstnew_malloc(&((*d)->moin), 1));
			if (tmp[0] == 'x' && (*d)->type == 'p')
			{
				ft_lstadd_front(cur, ft_lstnew_malloc(&tmp[0], 1));
				ft_lstadd_front(cur, ft_lstnew_malloc(&(*d)->zero, 1));
			}
		}
	}
	if ((*d)->type == '%')
		(*d)->prec = 1;
	return (1);
}

int		ft_appli_moin(t_arg **d, t_list **cur, int len, int len_e)
{
	t_list		*tmp;

	if ((*d)->type == 's' && (*d)->size < len)
		len_e = len_e + len - (*d)->size;
	if ((*d)->prec == 0 && (*d)->type == 's' && (*d)->ptrnull != 0)
		len_e = len - 1;
	if ((*d)->prec == 0 && (*d)->type == 'd' && (*d)->size == len_e)
		len_e--;
	if ((*d)->prec == len_e && (*d)->type == 's' && (*d)->prec > (*d)->size)
		return (1);
	while (len_e < len)
	{
		if (!(tmp = ft_lstnew_malloc(&((*d)->espace), 1)))
			return (0);
		ft_lstadd_back(cur, tmp);
		len_e++;
	}
	return (1);
}

int		ft_appli_zero(t_arg **d, t_list **cur, int len, int *len_e)
{
	char	*tmp;
	t_list	*lst_tmp;
	t_list	*temp;

	tmp = (*cur)->content;
	lst_tmp = (*cur);
	if ((*d)->type == 'i' || (*d)->type == 'd')
		if (tmp && tmp[0] == '-')
			(*cur) = (*cur)->next;
	while (*len_e < len && ((*d)->prec == -9999 || (*d)->type == '%'))
	{
		if (!(temp = ft_lstnew_malloc(&(*d)->zero, 1)))
			return (0);
		ft_lstadd_front(cur, temp);
		(*len_e)++;
	}
	if ((*d)->prec == 0 && (*d)->elem->content == NULL)
		(*len_e)--;
	if (tmp && tmp[0] == '-')
	{
		lst_tmp->next = *cur;
		(*cur) = lst_tmp;
	}
	return (1);
}
