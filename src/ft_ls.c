#include "ft_ls.h"
#include <stdio.h>

t_ls 	*new_lst(char *name)
{
	t_ls *ls;

	if(!(ls = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit (0);
	ls->name = ft_strdup(name);
	ls->next = NULL;
	return (ls);
}


t_ls	*add_list(t_ls *lst, char *file)
{
	t_ls *tmp;

	if (!lst->name)
	{	
		lst->name = ft_strdup(file);
		lst->next = NULL;
		return(lst);
	}
	else
	{
	 	tmp = lst;
	 	while (tmp->next)
	 		tmp = tmp->next;
		tmp->next = new_lst(file);
	}
	return(lst); // on renvoi le maillon de depart de list;
}
#include "string.h"
void 	print_lst(t_ls *lst)
{
	t_ls *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putstr(tmp->name);
		tmp = tmp->next;
	}
}

t_ls	*stock_list(t_ls *lst, struct dirent *file, DIR *dir)
{
	int i;

	i = 0;

	if(!(file = readdir(dir)))
	{
		perror("readdir :");
		return(0);
	}
	while((file = readdir(dir)))
		lst = add_list(lst, file->d_name); 
	return (lst);
}


void		ls_simple(void)
	{
		t_ls *lst;
		if(!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))  // initialise le premier element de ma list vaux mieux en faire une fct
			exit (0);
		lst->name = NULL;
		lst->next = NULL;
		DIR *dir;
		dir = NULL;
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
