#include "ft_ls.h"

static	int		check_sort_time(t_ls *lst)
{
	while (lst->next)
	{
		if (lst->data.t < lst->next->data.t)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_list_time(t_ls *lst)
{
	t_ls *tmp;

	tmp = lst;
	while (check_sort_time(tmp) == 0)
	{
		while(tmp->next)
		{
			if (tmp->data.t < tmp->next->data.t)
			{
				swap_data(tmp);
				tmp = lst;
			}
			else
				tmp = tmp->next;
		}
		tmp = lst;
	}
}
