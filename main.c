/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:00:25 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/16 18:55:12 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	char c = 'A';
	int	n = 100;
	int	n2 = 154;
	char	*str = "BONJOUR";
	
	int i1;
	int i2;	

	printf("reel : \n");
	i1 = printf(av[1], n, str);
	printf("\ntest : \n");
	i2 = ft_printf(av[1], n, str);
	printf("\nr : %i\nt : %i\n", i1, i2);


/*
	printf("compare: \"%19p\" \n", &n);
	ft_printf("result : \"%19p\" \n", &n);
	*/
}
