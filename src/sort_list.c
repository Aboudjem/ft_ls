#include "ft_ls.h"

static	int		check_sort(t_ls *lst)
{
	while (lst->next)
	{
		if (!(ft_strcmp(lst->data.name, lst->next->data.name) < 0))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	swap_data(t_ls *tmp)
{
	t_data data;

	data = tmp->data;
	tmp->data = tmp->next->data;
	tmp->next->data = data;
}

void	sort_list(t_ls *lst)
{
	t_ls *tmp;

	tmp = lst;
	while (check_sort(tmp) == 0)
	{
		if (ft_strcmp(tmp->data.name, tmp->next->data.name) > 0)
		{
			swap_data(tmp);
			tmp = lst;
		}
		tmp = tmp->next;
	}
}
