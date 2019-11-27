/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lst_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:54:12 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 11:20:51 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digilen_base(unsigned int n, unsigned int baselen)
{
	unsigned int		ret;

	ret = 0;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

t_list	*ft_pnblu(unsigned int n, unsigned int baselen, char *base, t_list **li)
{
	unsigned int		len;
	unsigned int		i;
	t_list				*tmp;

	i = 0;
	len = ft_digilen_base(n, baselen);
	if (n == 0)
		return (ft_lstnew(NULL));
	while (i < len)
	{
		tmp = ft_lstnew_malloc(&base[n % baselen], 1);
		if (tmp == NULL)
			return (NULL);
		ft_lstadd_front(li, tmp);
		n = n / baselen;
		i++;
	}
	return (*li);
}
