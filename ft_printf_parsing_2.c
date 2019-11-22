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

#include "ft_printf.h"

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
