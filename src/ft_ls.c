#include "ft_ls.h"

t_ls 	*new_lst(t_dir *file, t_stat buf)
{
	t_ls *ls;

	if(!(ls = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit (0);
	ls->mod = get_mod(buf, get_type(file->d_type));
	ls->user = get_uid(buf.st_uid);
	ls->group = get_gid(buf.st_gid);
	ls->size = buf.st_size;
	ls->time = get_time(buf.st_mtime);
	ls->name = ft_strdup(file->d_name);
	ls->next = NULL;
	return (ls);
}

t_ls	*add_list(t_ls *lst, t_dir *file, t_stat buf)
{
	t_ls *tmp;

	if (!lst->name)
	{	
		lst->mod = get_mod(buf, get_type(file->d_type));
		lst->user = get_uid(buf.st_uid);
		lst->group = get_gid(buf.st_gid);
		lst->size = buf.st_size;
		lst->time = get_time(buf.st_mtime);
		lst->name = ft_strdup(file->d_name);
		lst->next = NULL;
		return(lst);
	}
	else
	{
	 	tmp = lst;
	 	while (tmp->next)
	 		tmp = tmp->next;
		tmp->next = new_lst(file, buf);
	}
	return(lst); // on renvoi le maillon de depart de list;
}

void 	print_lst(t_ls *lst)
{
	t_ls *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("[%s][%s][%s][%d][%s][%s]\n", tmp->mod, tmp->user, tmp->group, tmp->size, tmp->time, tmp->name);
		// ft_putstr(tmp->name);
		tmp = tmp->next;
	}
}

t_ls	*stock_list(t_ls *lst, t_dir *file, DIR *dir)
{
	int i;
	t_stat buf;

	i = 0;
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

		f.a = 0;

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

