/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:53:22 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/21 10:53:25 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digitlen_base(int n, int baselen)
{
	int		ret;

	ret = 0;
	while (n != 0)
	{
		n = n / baselen;
		ret++;
	}
	return (ret);
}

t_list			*ft_putnbr_base_lst(int n, int baselen, char *base, t_list **li)
{
	int		len;
	int		i;
	t_list	*tmp;

	i = 0;
	len = ft_digitlen_base(n, baselen);
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
