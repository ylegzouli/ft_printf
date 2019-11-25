#include "ft_printf.h"

int		main()
{
	void *ptr_null = NULL;
	int ret;
	int ret2;
	
	ft_printf("\n-------------------------------------------\n");
	ret = printf("%05.*d\n", -15, 45);
	ret2 = ft_printf("%05.*d\n", -15, 45);
	printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%05.*u\n", -15, 45);
    ret2 = ft_printf("%05.*u\n", -15, 45);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%*.*u\n", -20, -15, 45);
    ret2 = ft_printf("%*.*u\n", -20, -15, 45);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%05.7x  %05.13x\n", 0, 0);
    ret2 = ft_printf("%05.7x  %05.13x\n", 0, 0);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%15p\n", ptr_null);
    ret2 = ft_printf("%15p\n", ptr_null);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("%-15p\n", ptr_null);
    ret2 = ft_printf("%-15p\n", ptr_null);
    printf("\n%d  %d\n", ret, ret2);
	
	ft_printf("\n-------------------------------------------\n");
}
