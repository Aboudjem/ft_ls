#include "ft_ls.h"

void	sorting(t_ls *tmp, t_flags f)
{
		sort_list(tmp);
	if (CHECK_BIT(f.bit, T))
		sort_list_time(tmp);
	if (CHECK_BIT(f.bit, R))
		while(tmp->next)
			tmp = tmp->next;
}
