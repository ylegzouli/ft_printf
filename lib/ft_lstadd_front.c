/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:51:39 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/07 12:34:57 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*li;

	if (!alst || !new)
		return ;
	li = *alst;
	new->next = li;
	*alst = new;
}
