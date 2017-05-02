#include "ft_ls.h"

size_t	ft_get_size(t_ls *tmp)
{
	size_t i;

	i = 0;
	while(tmp)
	{
		if ((size_t)tmp->data.size > i)
			i = (size_t)tmp->data.size;
		tmp = tmp->next;
	}
return((size_t)ft_len_int((int)i));
}

t_ls	*stock_list(t_ls *lst, t_dir *file, DIR *dir, char *d)
{
	t_stat buf;
	char *path;
	path = NULL;

	while((file = readdir(dir)))
	{
		path = ft_strjoin(d, file->d_name);
		if ((stat(path, &buf)) == -1)
			stat(file->d_name, &buf);
		add_list(lst, file, buf);
		free(path);
	}
	return (lst);
}

void		ls_dir(char *d, t_flags f)
{
	t_ls *lst;
	if(!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit (0);
	DIR *dir;
	t_dir *file;
	file = NULL;
	dir = opendir(d);
	if (dir == NULL)
		exit(0);
	stock_list(lst, file, dir, d);
	sorting(lst, f);
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
				{
					ft_putstr(argv[i]);
					i++;
				}
		while (i < argc)
		{
			if (!(opendir(argv[i])))
				printf("ls: %s: No such file or directory\n", argv[i]);
			else
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
				ls_dir(argv[i], f);
				ft_putstr("\n");
			}
			i++;
		}
		ft_putstr("\n");
		ls_dir(".", f);
		print_flags(f);
	}
	return(0);
}

