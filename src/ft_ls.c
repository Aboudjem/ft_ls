#include "ft_ls.h"

void 	print_lst(t_ls *lst)
{
	t_ls *tmp;
	tmp = lst;
	sort_list(tmp);
	while (tmp)
	{
		ft_putstr(tmp->data.name);
		ft_putstr("\n");
		tmp = tmp->next;
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

void		ls_dir(char *d)
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
	print_lst(lst);
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
		ls_dir(".");
	while (i < argc && check_flags(argv[i], &f))
		ft_putnbr(i++);
	while (i < argc)
	{
		if (!(opendir(argv[i])))
			printf("ls: %s: No such file or directory\n", argv[i]);
		else
			printf("%s\n",argv[i]);
		i++;
	}
	print_flags(f);
	return(0);
}

