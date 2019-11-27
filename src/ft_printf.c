/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylegzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:58:36 by ylegzoul          #+#    #+#             */
/*   Updated: 2019/11/25 16:36:28 by ylegzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	t_list	*li;
	int		ret;
	t_arg	*d;

	ret = 0;
	if (format == '\0')
		return (0);
	if (!(d = malloc(sizeof(t_arg))))
		return (0);
	d->sizenull = 0;
	va_start(arg, format);
	if (!(li = ft_lstnew(NULL)))
		return (0);
	if (!(ft_start(format, &arg, &li, &d)))
	{
		ft_free_d(&li, &d);
		return (0);
	}
	va_end(arg);
	ft_print_lst_char(li);
	ret = ft_lstsize(li) - 1 - d->sizenull;
	ft_free_d(&li, &d);
//	printf("size:%d\ncurrent:%s\nflag:%s\ntype:%c\nprec:%d\nptrnull:%d", d->size, d->current, d->fl, d->type, d->prec, d->ptrnull);
	return (ret);
}

int		ft_start(const char *format, va_list *arg, t_list **li, t_arg **d)
{
	char		*next_arg;

	next_arg = ft_strchr(format, '%');
	//printf("size:%d\ncurrent:%s\nflag:%s\ntype:%c\nprec:%d\nptrnull:%d", (*d)->size, (*d)->current, (*d)->fl, (*d)->type, (*d)->prec, (*d)->ptrnull);
	if (next_arg == NULL)
	{
		if (!(ft_tab_to_lst((li), (char *)format, ft_strlen(format))))
			return (0);
	}
	else if (next_arg > format)
	{
		if (!(ft_tab_to_lst(li, (char *)format, (next_arg - format))))
			return (0);
		if (!(ft_start(next_arg, arg, li, d)))
			return (0);
	}
	else
	{
		if (!(ft_start_opt(next_arg, arg, li, d)))
			return (0);
	}
	return (1);
}

int		ft_start_opt(char *next_arg, va_list *arg, t_list **li, t_arg **d)
{
//	if (!((*d) = malloc(sizeof(t_arg))))
//		return (0);
	if (!(ft_init_d(d)))
		return (0);
	ft_def_flag(next_arg, d, arg);
	ft_def_size((*d)->current, d, arg);
	ft_def_preci((*d)->current, d, arg);
	ft_def_type((*d)->current, arg, d, li);
	if ((*d)->type == '\0')
		return (0);
	if (!(ft_convert(d, arg)))
		return (0);
	if (!(ft_appli(d, li)))
		return (0);
	next_arg = (*d)->current + 1;
	if (!(ft_start(next_arg, arg, li, d)))
		return (0);
	return (1);
}

int		ft_init_d(t_arg **d)
{
	int		i;

	i = 0;
	(*d)->size = -9999;
	(*d)->type = '\0';
	(*d)->ptrnull = 0;
	if (!((*d)->elem = ft_lstnew(NULL)))
		return (0);
	(*d)->prec = -9999;
	while (i < (NB_FLAG))
	{
		((*d)->fl)[i] = '\0';
		i++;
	}
	((*d)->fl)[i] = '\0';
	(*d)->espace = ' ';
	(*d)->zero = '0';
	(*d)->moin = '-';
	((*d)->str_null)[0] = '(';
	((*d)->str_null)[1] = 'n';
	((*d)->str_null)[2] = 'u';
	((*d)->str_null)[3] = 'l';
	((*d)->str_null)[4] = 'l';
	((*d)->str_null)[5] = ')';
	((*d)->str_null)[6] = '\0';
	return (1);
}

void	ft_free_d(t_list **li, t_arg **d)
{
	ft_lstclear(li, &free);
	free(*d);
}
