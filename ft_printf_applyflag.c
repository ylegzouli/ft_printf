#include "ft_printf.h"

void        ft_appli_flag(t_arg **argument, t_list **li)
{
	int		len;
	int		len_elem;
	t_list	*cur;
 
 	len_elem = ft_lstsize((*argument)->elem);
 	if ((*argument)->size > len_elem)
        len = (*argument)->size + 1;
    else
        len = len_elem + 1;
	if (ft_strchr((*argument)->flags, '-') != NULL)
	{
		ft_lstadd_back()


	}
//	if (ft_strchr((*argument)->flags, '0') != NULL)	
//	if (ft_strchr((*argument)->flags, '.') != NULL)	
	ft_lstadd_back(li, (*argument)->elem);
//	ft_print_lst_char(*li);
}
