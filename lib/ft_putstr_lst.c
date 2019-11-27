/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:33:35 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 10:50:04 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_putstr_lst(char *s, t_list **li)
{
	int	i;
	int ret;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ret = ft_putchar_lst(s[i], li);
		if (ret == 0)
			return (0);
		i++;
	}
	return (1);
}
