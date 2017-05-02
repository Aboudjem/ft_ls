#include "ft_ls.h"

void	print_full(t_data d, size_t i)
{
	char *s;
	s = ft_strnew(i);
	ft_putstr(d.mod);
	ft_putstr("  ");
	if (ft_len_int((int)d.link) != 2)
		ft_putstr(" ");
	ft_putnbr((int)d.link);
	ft_putstr(" ");
	ft_putstr(d.user);
	ft_putstr("  ");
	ft_putstr(d.group);
	ft_memset(s, ' ', (i - (size_t)ft_len_int((int)d.size) + 2));
	ft_putstr(s);
	ft_putnbr((int)d.size);
	ft_putstr(" ");
	ft_putstr(d.time);
	ft_putstr(" ");
	ft_putstr(d.name);
}

void	print_data(t_ls *tmp, t_flags f, size_t i)
{
	while (tmp)
	{
		if (!(CHECK_BIT(f.bit, A)) && tmp->data.name[0] == '.')
			tmp = tmp->next;
		else
		{
			if (!(CHECK_BIT(f.bit, L)))
				ft_putstr(tmp->data.name);
			else
				print_full(tmp->data, i);
			ft_putstr("\n");
		}
			tmp = tmp->next;
	}
}


void 	print_lst(t_ls *lst, t_flags f)
{
	t_ls *tmp;
	size_t i;
	sorting(lst, f);

	tmp = lst;
	i = ft_get_size(tmp);

	if (!(CHECK_BIT(f.bit, R)))
		print_data(tmp, f, i);
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			if (!(CHECK_BIT(f.bit, L)))
				ft_putstr(tmp->data.name);
			else
				print_full(tmp->data, i);
			ft_putstr("\n");
			tmp = tmp->back;
		}
	}
}
