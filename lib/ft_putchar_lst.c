/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:23:13 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 10:52:57 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_lst(char c, t_list **li)
{
	t_list *tmp;

	tmp = ft_lstnew_malloc(&c, 1);
	if (tmp == NULL)
		return (0);
	ft_lstadd_back(li, tmp);
	return (1);
}
