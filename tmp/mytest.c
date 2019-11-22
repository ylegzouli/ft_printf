#include "ft_printf.h"
#include "stdio.h"

int main(int ac, char **av)
{
	int i;
	unsigned int u;
	int x;
	char c;
	char *p;
	char s1[] = "qwertyuiop";
	char *s;

	s = 0;
	i = 4542;
	u = 2200424242;
	c = 'a';
	p = &c;
	x = 4835;

	printf("Test sur int\n");
	printf("Test 1\n");
	ft_printf("number =%-10.6i top\n", i);
	printf("number =%-10.6i top\n\n",i);
	printf("Test 2\n");
	ft_printf("number =%*d top\n", 10,i);
	printf("number =%*d top\n\n",10,i);
	printf("Test 3\n");
	ft_printf("number =%*i top\n", 15, -2147483648);
	printf("number =%*i top\n\n",15, -2147483648);
	printf("Test 4\n");
	ft_printf("number =%-*i top\n", 15, 2147483647);
	printf("number =%-*i top\n\n",15, 2147483647);
	printf("Test 5\n");
	ft_printf("number =%0*i top\n", 5, 2);
	printf("number =%0*i top\n\n",5, 2);

	printf("Test sur unsigned int\n");
	printf("Test 6\n");
	ft_printf("number =%-27.15u top\n", u);
	printf("number =%-27.15u top\n\n",u);
	printf("Test 7\n");
	ft_printf("number =%0-*.17u top\n", 25,u);
	printf("number =%0-*.17u top\n\n",25,u);
	
	printf("Test sur string\n");
	printf("Test 8\n");
	ft_printf("str =%.8s top\n", s);
	printf("str =%.8s top\n\n", s);
	printf("Test 9\n");
	ft_printf("str =%.3s top\n", s);
	printf("str =%.3s top\n\n", s);

	printf("Test sur hexa\n");
	printf("Test 10\n");
	ft_printf("hexa =%-12.7X top\n", x);
	printf("hexa =%-12.7X top\n\n", x);
	printf("Test 11\n");
	ft_printf("hexa =%0*.7x top\n", 25,x);
	printf("hexa =%0*.7x top\n\n", 25,x);

	printf("Test sur pointeur\n");
	printf("Test 12\n");
	ft_printf("ptr =%p top\n", p);
	printf("ptr =%p top\n\n", p);
	printf("Test 14\n");
	ft_printf("ptr =%-15p top\n", p);
	printf("ptr =%-15p top\n\n", p);
	printf("Test 15\n");
	ft_printf("ptr =%50p top\n", p);
	printf("ptr =%50p top\n\n", p);
	printf("Test 16\n");
	ft_printf("ptr =%*p top\n", 30,p);
	printf("ptr =%*p top\n\n", 30,p);
	
//	while(1)
//	{}

	int		len;
	int		i1;
	int		i2;

	char	*str = 0;
	char	*str2 = "hello";
	int 	nb = 143;

	len = ft_strlen(av[1]) - 1;

	printf("\n---------------------------------------A FIX-------------------------------------\n");

	printf("\n1.					[%%p]\n");
	i1 = printf("compare: \"%p\" \n", &malloc) - 13;
	i2 = ft_printf("result : \"%p\"", &malloc) - 11;
	printf("\n[%d][%d]", i1, i2);

	printf("\n\n2.					[%%xX]\n");
    i1 = printf("compare: \"%x\" \n", 243775) -13;
    i2 = ft_printf("result : \"%x\"", 243775) -11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n3.					[%%s]  (chaine null)\n");
	i1 = printf("compare: \"%s\" \n", str) - 13;
	i2 = ft_printf("result : \"%s\"", str) - 11;
	printf("\n[%d][%d]", i1, i2);
	
	printf("\n\n3.5					[%%.3s]  (chaine null tronque)\n");
	i1 = printf("compare: \"%.3s\" \n", str) - 13;
	i2 = ft_printf("result : \"%.3s\"", str) - 11;
	printf("\n[%d][%d]", i1, i2);

	printf("\n\n4.					[%%10.8s]  (preci > size_elem?)\n");
    i1 = printf("compare: \"%10.8s\" \n", str2) - 13;
    i2 = ft_printf("result : \"%10.8s\"", str2) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n5.					[%%.7i]  (preci < avec un negatif)\n");
    i1 = printf("compare: \"%.7i\" \n", -442) - 13;
    i2 = ft_printf("result : \"%.7i\"", -442) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n6.					[%%-4.16d]\n");
    i1 = printf("compare: \"%-4.16d\" \n", nb) - 13;
    i2 = ft_printf("result : \"%-4.16d\"", nb) - 11;
    printf("\n[%d][%d]", i1, i2);

 	printf("\n\n7.					[%%025.6d]\n");
    i1 = printf("compare: \"%025.6d\" \n", nb) - 13;
    i2 = ft_printf("result : \"%025.6d\"", nb) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n8.[FIX]					[%%6.9s]\n");
    i1 = printf("compare: \"%6.9s\" \n", "abcdef") - 13;
    i2 = ft_printf("result : \"%6.9s\"", "abcdef") - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n9.					[%%.6d]\n");
    i1 = printf("compare: \"%.6d\" \n", 342) - 13;
    i2 = ft_printf("result : \"%.6d\"", 342) - 11;
    printf("\n[%d][%d]", i1, i2);

	printf("\n\n9.                  [%%.6d]\n");
    i1 = printf("compare: \"%.6d\" \n", -44342) - 13;
    i2 = ft_printf("result : \"%.6d\"", -44342) - 11;
    printf("\n[%d][%d]", i1, i2);

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
	else if (av[1][len] == 'd' || av[1][len] == 'i' || av[1][len] == 'x' || av[1][len] == 'X')
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
