/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:00:25 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/13 17:49:25 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	char c = 'A';
	int	n = 37465;

	printf("compare: \"%d\" \n", n);
	ft_printf("result : \"%d\" \n", n);
}
