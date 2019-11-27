/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:49:50 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/22 16:32:20 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tab_to_lst(t_list **li, char *tab, size_t size)
{
	size_t		i;
	t_list		*tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_lstnew_malloc(&tab[i], 1);
		if (tmp == NULL)
			return (0);
		ft_lstadd_back(li, tmp);
		i++;
	}
	return (1);
}
