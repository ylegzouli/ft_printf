#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../inc/ft_printf.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	if (s1[i] != s2[i])
		return (-1);
	return (0);
}

void	ft_rescmp(char * s1, int len, int numtest)
{
	int fd;
	int i;
	char s2[len + 1];

	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("%i>>", numtest);
	fd = open("out.txt", O_RDONLY);
	i = 0;
	while (i <= (len))
	{
		s2[i] = 0;
		i++;
	}
	read(fd, s2, len);
//	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("\ns1 =%s\ns2 =%s\n", s1, s2); //remove comments to see the results
	if (!(ft_strcmp(s1, s2)))
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;32m"); printf("OK\n");
	}
	else
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;31m"); printf("KO\n");
	}
}

void	ft_test(char *str, void *conv, char c, int *numtest)
{
	FILE *out = freopen("./out.txt", "w", stdout);
	int len;
	char *s1;
	int lenft;

	if (c == 's')
		(char *)conv;
	if (c == 'c')
		(char)conv;
	if (c == 'p')
		(int *)conv;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		(int)conv;
	if (c == 'u')
		(unsigned int)conv;
	*numtest += 1;
	lenft = ft_printf(str, conv);
	len = snprintf(NULL, 0, str, conv);
	s1 = malloc(len + 1);
	snprintf(s1, len + 1, str, conv);
	ft_rescmp(s1, len, *numtest);
//	freopen ("/dev/tty", "a", stdout); printf("\033[0m"); printf("len f =%i\nlen t =%i\n", lenft, len); //remove comments to see length
	if (lenft != len)
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;31m"); printf("return error\n");
	}
	else
	{
		freopen ("/dev/tty", "a", stdout); printf("\033[1;32m"); printf("return ok\n");
	}
}

int main()
{
	int num = 0;
	int *numtest = &num;
	char *str = "ca marche !";
	char *str2 = "";
	char *str3 = NULL;
	char c = 'z';
	char c2 = 0;
	int i = 42;
	int i2 = 0;
	int i3 = -42;
	int *p = &i;
	int *p2 = NULL;
	unsigned int u = 394;

	freopen ("/dev/tty", "a", stdout); printf("\033[0;97m"); printf("-----basic tests-----\n");
	ft_test("%s", str, 's', numtest);
	ft_test("%s", str2, 's', numtest);
	ft_test("%s", str3, 's', numtest);
	ft_test("%c", c, 'c', numtest);
	ft_test("%c", c2, 'c', numtest);
	ft_test("%p", p, 'p', numtest);
	ft_test("%p", p2, 'p', numtest);
	ft_test("%i", i, 'i', numtest);
	ft_test("%d", i2, 'd', numtest);
	ft_test("%i", i3, 'i', numtest);
	ft_test("%x", i, 'x', numtest);
	ft_test("%x", i2, 'x', numtest);
	ft_test("%x", i3, 'x', numtest);
	ft_test("%X", i, 'X', numtest);
	ft_test("%X", i2, 'X', numtest);
	ft_test("%X", i3, 'X', numtest);
	ft_test("%u", u, 'u', numtest);
	freopen ("/dev/tty", "a", stdout); printf("\033[0;97m"); printf("-----advanced tests-----\n");
	ft_test("%05i", i, 'i', numtest);
	ft_test("%.-5i", i, 'i', numtest);
	ft_test("%.-5i", i, 'i', numtest);
	ft_test("%-9c", c, 'c', numtest);
	ft_test("%9c", c, 'c', numtest);
	ft_test("%9s", str, 's', numtest);
	ft_test("%-9s", str, 's', numtest);
	ft_test("%.9s", str, 's', numtest);
	ft_test("%9s", str2, 's', numtest);
	ft_test("%-9s", str2, 's', numtest);
	ft_test("%.9s", str2, 's', numtest);
	ft_test("%9s", str3, 's', numtest);
	ft_test("%-9s", str3, 's', numtest);
	ft_test("%.9s", str3, 's', numtest);
	ft_test("%-21p", p, 'p', numtest);
	ft_test("%21p", p, 'p', numtest);
	ft_test("%21p", p2, 'p', numtest);
	ft_test("%-21p", p2, 'p', numtest);

	return (0);
}
