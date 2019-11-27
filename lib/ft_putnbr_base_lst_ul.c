/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lst_ul.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:05:35 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 11:06:44 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlen_base(unsigned long n, unsigned long baselen)
{
	unsigned long		ret;

	ret = 0;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

t_list	*ft_pnblul(unsigned long n, unsigned long blen, char *b, t_list **li)
{
	unsigned long		len;
	unsigned long		i;
	t_list				*tmp;

	i = 0;
	len = ft_digitlen_base(n, blen);
	if (n == 0)
		return (ft_lstnew(NULL));
	while (i < len)
	{
		tmp = ft_lstnew_malloc(&b[n % blen], 1);
		if (tmp == NULL)
			return (NULL);
		ft_lstadd_front(li, tmp);
		n = n / blen;
		i++;
	}
	return (*li);
}
