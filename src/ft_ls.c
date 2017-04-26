#include "ft_ls.h"


void	sort_alpha(t_ls *lst)
{
	t_ls	*tmp;
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		printf("--[%s]\n", tmp->name);
		tmp = tmp->next;
	}
}

void	stock_list(t_ls *lst, struct dirent *file, DIR *dir)
{
	int i;

	i = 0;
	while ((file = readdir(dir)) != NULL)
	{
		if ((lst = ft_memalloc(sizeof(t_ls))) == NULL)
			exit (1);
		lst->name = ft_strdup(file->d_name);
		// ft_putstr(lst->name);
		//ft_putstr("\n");
		lst->next = NULL;
		lst = lst->next;
		i++;
		sort_alpha(lst);
	}
}


void		ls_simple(void)
	{
		t_ls *lst;
		lst = NULL;
		DIR *dir;
		dir = NULL;
		struct dirent *file = NULL;
		dir = opendir(".");
		if (dir == NULL)
		{
			ft_putstr("DIR = NULL\n");
			exit(0);
		}
		stock_list(&lst, file, dir);
		if (closedir(dir) == -1)
			exit(-1);
	}

	int			main(int argc, char *argv[])
	{
		int i;
		t_flags f;

		i = 1;
		if (argc == 1)
			ls_simple();
		while (i < argc && check_flags(argv[i], &f))
			ft_putnbr(i++);
		while (i < argc)
		{
			ft_putstr("LA");
			i++;
		}
		// while (i < argc)

		print_flags(f);
		return(0);
	}
