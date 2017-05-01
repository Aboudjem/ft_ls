#include "ft_ls.h"

static	int		check_sort_reverse(t_ls *lst)
{
	while (lst->next)
	{
		if (!(ft_strcmp(lst->data.name, lst->next->data.name) > 0))
			return (0);

		lst = lst->next;
	}
	return (1);
}

void	sort_reverse(t_ls *lst)
{
	t_ls *tmp;

	tmp = lst;
	while (check_sort_reverse(tmp) == 0)
		{
			while(tmp->next)
				{
				if (ft_strcmp(tmp->data.name, tmp->next->data.name) < 0)
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
