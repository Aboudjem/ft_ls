#include "ft_ls.h"

void 	print_lst(t_ls *lst)
{
	t_ls *tmp;
	tmp = lst;
	sort_list(tmp);
	while (tmp)
	{
		ft_putstr(tmp->data.name);
		ft_putstr("   ");
		tmp = tmp->next;
	}
}

t_ls	*stock_list(t_ls *lst, t_dir *file, DIR *dir)
{
	t_stat buf;

	if(!(file = readdir(dir)))
	{
		perror("readdir :");
		return(0);
	}
	while((file = readdir(dir)))
	{
		stat(file->d_name, &buf);
		lst = add_list(lst, file, buf);
	}
	return (lst);
}

void		ls_simple(void)
{
	t_ls *lst;
	if(!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))  // initialise le premier element de ma list vaux mieux en faire une fct
		exit (0);
	DIR *dir;
	struct dirent *file = NULL;
	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("DIR = NULL\n");
		exit(0);
	}
	stock_list(lst, file, dir);
	print_lst(lst);	
	if (closedir(dir) == -1)
		exit(-1);
}

void	init_flags(t_flags *f)
{	
	f->l = 0;
	f->a = 0;
	f->r = 0;
	f->t = 0;
	f->rr = 0;
	f->bit = 0;
}

int			main(int argc, char *argv[])
{
	int i;
	t_flags f;
	init_flags(&f);

	i = 1;
	if (argc == 1)
		ls_simple();
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

