#include "ft_printf.h"

int		main()
{
	void *ptr = NULL;
	int	ret;
	int	ret2;
	ret = printf("%0*.*d\n", -20, -10, 45);
	ret2 = ft_printf("%0*.*d\n", -20, -10, 45);
	printf("\n%d  %d\n", ret, ret2);
//	while(1)
//	{}
}
