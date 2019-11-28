#include "../inc/ft_printf.h"

int		main()
{
	void *ptr_null = NULL;
	int ret;
	int ret2;
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
	ft_printf("\n-------------------------------------------\n");
	 ret = printf("|%.*d|\n", -9999, 2);
    ret2 = ft_printf("|%.*d|\n", -9999, 2);
    printf("\n%d  %d\n", ret, ret2);

	ft_printf("\n-------------------------------------------\n");
	 ret = printf("|%05.*d|\n", -15, -42);
    ret2 = ft_printf("|%05.*d|\n", -15, -42);
    printf("\n%d  %d\n", ret, ret2);
		
	ft_printf("\n-------------------------------------------\n");
}
