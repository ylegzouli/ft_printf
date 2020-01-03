
int		main()
{
	int ret;
/*	
	ft_printf("\n-------------------------------------------\n");
	ret = printf("%000000000.*i\n", 0xff, 0xff);
	ret2 = ft_printf("%0000000000.*i\n", 0xff, 0xff);
	printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%.0s\n", "bonjour");
    ret2 = ft_printf("%.0s\n", "bonjour");
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
    ret2 = ft_printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("|%-5.0x|\n" , 0);
    ret2 = ft_printf("|%-5.0x|\n" , 0);
    printf("\n%d  %d\n", ret, ret2);
*/
	ret = printf("|%.10d|\n", -2543) - 3;
    printf("%d\n", ret);
	
	ret = printf("|%5.2s|\n", "bonjour") - 3;
    printf("%d\n", ret);
	
	ret = printf("|%3x|\n", 223) - 3;
    printf("%d\n", ret);



/*	ft_printf("\n-------------------------------------------\n");
	 ret = printf("|%05.*d|\n", -15, -42);
    ret2 = ft_printf("|%05.*d|\n", -15, -42);
    printf("\n%d  %d\n", ret, ret2);
		
	ft_printf("\n-------------------------------------------\n");
	*/
	}
