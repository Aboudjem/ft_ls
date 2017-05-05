#include "ft_ls.h"

void	print_dir(char *argv, t_flags f)
{
			if (!(opendir(argv)))
				printf("ls: %s: No such file or directory\n", argv);
			else
			{
				ft_putstr("\n");
				ft_putstr(argv);
				ft_putstr(":\n");
				ls_dir(ft_strjoin(argv, "/") , f);
			}
}

void	print_full(t_data d, t_size s)
{
	char *s1;
	char *s2;
	char *s3;
	char *s4;

	s1 = ft_strnew(s.link + 2);
	s2 = ft_strnew(s.user + 1);
	s3 = ft_strnew(s.group + 2);
	s4 = ft_strnew(s.size + 2);
	ft_putstr(d.mod);
	ft_memset(s1, ' ', (s.link - (size_t)ft_len_int((int)d.link) + 2));
	ft_putstr(s1);
	ft_putnbr((int)d.link);
	ft_memset(s2, ' ', (s.user - ft_strlen(d.user) + 1));
	ft_putstr(s2);
	ft_putstr(d.user);
	ft_memset(s3, ' ', (s.group - ft_strlen(d.group) + 2));
	ft_putstr(s3);
	ft_putstr(d.group);
	ft_memset(s4, ' ', (s.size - (size_t)ft_len_int((int)d.size) + 3));
	ft_putstr(s4);
	ft_putnbr((int)d.size);
	ft_putstr(" ");
	ft_putstr(d.time);
	ft_putstr(" ");
	ft_putstr(d.name);
}

void	print_data(t_ls *tmp, t_flags f, t_size s)
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
				print_full(tmp->data, s);
			ft_putstr("\n");
		}
			tmp = tmp->next;
	}
}

void 	print_lst(t_ls *lst, t_flags f)
{
	t_ls *tmp;
	t_size s;
	sorting(lst, f);

	tmp = lst;
	s = ft_get_size(tmp);

	if (!(CHECK_BIT(f.bit, R)))
		print_data(tmp, f, s);
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			if (!(CHECK_BIT(f.bit, L)))
				ft_putstr(tmp->data.name);
			else
				print_full(tmp->data, s);
			ft_putstr("\n");
			tmp = tmp->back;
		}
	}
}
