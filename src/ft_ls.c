#include "ft_ls.h"

size_t	ft_get_size(t_ls *tmp)
{
	size_t i;

	i = 0;
	while(tmp)
	{
		if (tmp->data.size > i)
			i = tmp->data.size;
		tmp = tmp->next;
	}
return(i);
}

void 	print_lst(t_ls *lst, t_flags f)
{
	t_ls *tmp;
	size_t len_size;
	tmp = lst;

	len_size = ft_get_size(tmp);

	if (CHECK_BIT(f.bit, R))
		sort_reverse(tmp);
	else
		sort_list(tmp);

	if (CHECK_BIT(f.bit, T))
		sort_list_time(tmp);
	while (tmp)
	{
		// if (!(CHECK_BIT(f.bit, A)) && tmp->data.name[0] == '.')
		// 	tmp = tmp->next;
		// else
		// {
		// 	if (!(CHECK_BIT(f.bit, L)))
		// 		ft_putstr(tmp->data.name);
		// 	else
				print_full(tmp->data);
				ft_putstr("\n");
				tmp = tmp->next;
		// }
	}
}

t_ls	*stock_list(t_ls *lst, t_dir *file, DIR *dir)
{
	t_stat buf;

	while((file = readdir(dir)))
	{
		stat(file->d_name, &buf);
		lst = add_list(lst, file, buf);
	}
	return (lst);
}

void		ls_dir(char *d, t_flags f)
{
	t_ls *lst;
	if(!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit (0);
	DIR *dir;
	struct dirent *file = NULL;
	dir = opendir(d);
	if (dir == NULL)
		exit(0);
	stock_list(lst, file, dir);
	print_lst(lst, f);
	if (closedir(dir) == -1)
		exit(-1);
}

int			main(int argc, char *argv[])
{
	int i;
	t_flags f;
	init_flags(&f);

	i = 1;
	if (argc == 1)
		ls_dir(".", f);
	else
	{
		
	while (i < argc && check_flags(argv[i], &f))
			i++;
	while (i < argc)
	{
		if (!(opendir(argv[i])))
			printf("ls: %s: No such file or directory\n", argv[i]);
		else
			printf("%s\n",argv[i]);
		i++;
	}
		ls_dir(".", f);
	print_flags(f);
	}
	return(0);
}

