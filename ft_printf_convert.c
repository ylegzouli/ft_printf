/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:42:16 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/16 14:10:34 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_convert_str(t_arg **argument, va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char *);
	ft_putstr_lst(str, &((*argument)->elem));
}

void		ft_convert_char(t_arg **argument, va_list *arg)
{
	char	c;

	c = va_arg(*arg, int);
	ft_putchar_lst(c, &((*argument)->elem));
}

void        ft_convert_ptr(t_arg **argument, va_list *arg)
{
	void			*temp;
	unsigned long  	ptr;
	char			tmp;

	temp = va_arg(*arg, void *);
	ptr = (unsigned long)temp;
	ft_putnbr_base_lst_ul(ptr, 16, "0123456789abcdef", &((*argument)->elem));
	tmp = 'x';
	ft_lstadd_front(&((*argument)->elem), ft_lstnew_malloc(&tmp, 1));
	tmp = '0';
	ft_lstadd_front(&((*argument)->elem), ft_lstnew_malloc(&tmp, 1));
}

void        ft_convert_hexa(t_arg **argument, va_list *arg)
{
	unsigned int n;

	n = va_arg(*arg, unsigned int);

	if ((*argument)->type == 'x')
		ft_putnbr_base_lst_u(n, 16, "0123456789abcdef", &((*argument)->elem));
	if ((*argument)->type == 'X')
		ft_putnbr_base_lst_u(n, 16, "0123456789ABCDEF", &((*argument)->elem));
}

void        ft_convert_unsigned(t_arg **argument, va_list *arg)
{
	unsigned int n;
	
	n = va_arg(*arg, unsigned int);
	ft_putnbr_lst_u(n, &((*argument)->elem));
}

void        ft_convert_int(t_arg **argument, va_list *arg)
{
	int		n;

	n = va_arg(*arg, int);
	ft_putnbr_lst(n, &((*argument)->elem));
}

void        ft_convert_pcent(t_arg **argument, va_list *arg)
{
	ft_putchar_lst('%', &((*argument)->elem));
}

/*
void        ft_appli_flag(t_arg **argument, t_list **li)
{
	int		len_elem;
	int		len_tab;
	char	*tab;
	int		i;

	i = 0;
	len_elem = ft_strlen((*argument)->elem);
	printf("%d\n\n", (*argument)->size);
	if ((*argument)->size > len_elem)
		len_tab = (*argument)->size + 1;
	else
		len_tab = len_elem + 1;
	if(!(tab = malloc(sizeof(char) * (len_tab + 1))))
		return ;
	if (ft_strchr((*argument)->flags, '-') != NULL)
	{
		ft_strlcpy(tab, (*argument)->elem, len_elem);
		i = len_elem;
		if (ft_strchr((*argument)->flags, '0') != NULL)
			ft_memset(&tab[i], '0', (len_tab - len_elem));
		else
			ft_memset(&tab[i], ' ', (len_tab - len_elem));
	}
	else
	{
        if (ft_strchr((*argument)->flags, '0') != NULL)
            ft_memset(tab, '0', (len_tab - len_elem));
        else
            ft_memset(tab, ' ', (len_tab - len_elem));
		i = len_tab - len_elem - 1;
		ft_strlcpy(&tab[i], (*argument)->elem, len_elem + 1);
	}
	ft_tab_to_lst(li, tab, len_tab);
	return ; 
}*/
