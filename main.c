/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:00:25 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/18 18:08:35 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	int		len;
	int		i1;
	int		i2;

	char	*str = 0;
	char	*str2 = "hello";
	int 	nb = 143;

	len = ft_strlen(av[1]) - 1;

	printf("\n---------------------------------------A FIX-------------------------------------\n");

	printf("\n 1.[FIX]				[%%p]\n");
	i1 = printf("compare: \"%p\" \n", &malloc) - 13;
	i2 = ft_printf("result : \"%p\"", &malloc) - 11;
	printf("\n[%d][%d]", i1, i2);

	printf("\n\n2.[FIX]					[%%xX]\n");
    i1 = printf("compare: \"%x\" \n", 243775) -13;
    i2 = ft_printf("result : \"%x\"", 243775) -11;
    printf("\n[%d][%d]", i1, i2);

/*	printf("\n\n3.					[%%s]  (chaine null)\n");
	i1 = printf("compare: \"%s\" \n", str) - 13;
	i2 = ft_printf("result : \"%s\"", str) - 11;
	printf("\n[%d][%d]", i1, i2);*/

	printf("\n\n4.[FIX]					[%%10.8s]  (preci > size_elem?)\n");
    i1 = printf("compare: \"%10.8s\" \n", str2) - 13;
    i2 = ft_printf("result : \"%10.8s\"", str2) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n5.[FIX]					[%%.6s]  (preci < size?)\n");
    i1 = printf("compare: \"%.6s\" \n", "abcdefghijklmno") - 13;
    i2 = ft_printf("result : \"%.6s\"", "abcdefghijklmno") - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n6.[FIX]					[%%-4.16d]\n");
    i1 = printf("compare: \"%-4.16d\" \n", nb) - 13;
    i2 = ft_printf("result : \"%-4.16d\"", nb) - 11;
    printf("\n[%d][%d]", i1, i2);

 	printf("\n\n7.[FIX]					[%%025.6d]\n");
    i1 = printf("compare: \"%025.6d\" \n", nb) - 13;
    i2 = ft_printf("result : \"%025.6d\"", nb) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n8.[FIX]					[%%6.9s]\n");
    i1 = printf("compare: \"%6.9s\" \n", "abcdef") - 13;
    i2 = ft_printf("result : \"%6.9s\"", "abcdef") - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n9.[FIX]					[%%.6d]\n");
    i1 = printf("compare: \"%.6d\" \n", 342) - 13;
    i2 = ft_printf("result : \"%.6d\"", 342) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n10.[FIX]				[%%-*.5x]\n");
    i1 = printf("compare: \"%-*.5x\" \n", 12, 24356) - 13;
    i2 = ft_printf("result : \"%-*.5x\"", 12, 24356) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n11.[FIX]				[%%*.*d]\n");
    i1 = printf("compare: \"%*.*d\" \n", 15, 10, 42) - 13;
    i2 = ft_printf("result : \"%*.*d\"", 15, 10, 42) - 11;
    printf("\n[%d][%d]", i1, i2);

/*	 printf("\n\n4.                 [%%]\n");
    i1 = printf("compare: \"%\" \n", str2) - 13;
    i2 = ft_printf("result : \"%\"", str2) - 11;
    printf("\n[%d][%d]", i1, i2);

	 printf("\n\n4.                 [%%]\n");
    i1 = printf("compare: \"%\" \n", str2) - 13;
    i2 = ft_printf("result : \"%\"", str2) - 11;
    printf("\n[%d][%d]", i1, i2);
*/
	printf("\n\n-------------------------------------CURRENT TEST---------------------------------\n\n");

	ft_printf("\nFLAG=[%s]	|	ARG=[%s] \n\n", av[1], av[2]);

	if (av[1][len] == 's')
	{
		printf("compare: \"");
		i1 = printf(av[1], av[2]);
		printf("\"\n");
		ft_printf("result : \"");
		i2 = ft_printf(av[1], av[2]);
		printf("\"\n[%d][%d]\n", i1, i2);
	}
	else if (av[1][len] == 'c' || av[1][len] == '%')
    {
		printf("compare: \"");
        i1 = printf(av[1], av[2][0]);
		printf("\"\n");
		ft_printf("result : \"");
        i2 = ft_printf(av[1], av[2][0]);
		printf("\"\n[%d][%d]\n", i1, i2);
    }
	else if (av[1][len] == 'u' || av[1][len] == 'd' || av[1][len] == 'i' || av[1][len] == 'x' || av[1][len] == 'X')
    {
		printf("compare: \"");
        i1 = printf(av[1], atoi(av[2]));
		printf("\"\n");
		ft_printf("result : \"");
        i2 = ft_printf(av[1], atoi(av[2]));
		printf("\"\n[%d][%d]\n", i1, i2);
    }
	
	if (av[1][len] == 'p')
    {
        printf("compare: \"");
        i1 = printf(av[1], av[2]);
        printf("\"\n");
        ft_printf("result : \"");
        i2 = ft_printf(av[1], av[2]);
        printf("\"\n[%d][%d]\n", i1, i2);
    }

	printf("\n\n-------------------------------------------------------------------------------------\n");
}
