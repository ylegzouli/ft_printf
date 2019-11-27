/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:22:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/22 14:23:55 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	ft_is_type(char c)
{
	int		i;

	i = 0;
	while (TYPE[i])
	{
		if (c == TYPE[i])
			return (TYPE[i]);
		i++;
	}
	return ('\0');
}

char	ft_is_flag(char c)
{
	int		i;

	i = 0;
	while (FLAG[i])
	{
		if (c == FLAG[i])
			return (FLAG[i]);
		i++;
	}
	return ('\0');
}
/*
void		ft_clean_lst(t_list **li)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *li;
	while ((*li) != NULL)
	{
		tmp = (*li);
		(*li) = (*li)->next;
	}
	if ((*li)->next != NULL)
	{
		tmp->next = (*li)->next;
		free(*li);
	}
	*li = cur;
}

int			ft_lst_isempty(t_list *li)
{
	if (li == NULL)
		return (0);
	return (1);
}
*/
