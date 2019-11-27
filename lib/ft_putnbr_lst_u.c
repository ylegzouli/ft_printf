/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:23:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 11:08:50 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_lst_u(unsigned int nb, t_list **li)
{
	long unsigned int	n;
	char				tmp;
	int					ret;

	n = nb;
	if (n < 0)
	{
		n = -n;
		tmp = '-';
		if (!(ret = ft_putchar_lst(tmp, li)))
			return (0);
	}
	if (n <= 9)
	{
		tmp = n + '0';
		ret = ft_putchar_lst(tmp, li);
		if (ret == 0)
			return (0);
	}
	else
	{
		ft_putnbr_lst(n / 10, li);
		ft_putnbr_lst(n % 10, li);
	}
	return (1);
}
