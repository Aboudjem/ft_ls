#include "ft_ls.h"

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

// void		stock_r(t_ls *lst, t_flags f, char *d)
// {
// 	DIR *dir;
// 	char *path;
// 	if (!(dir = opendir(d)))
// 		exit (0);
// 	t_dir *file;
// 	if (dir == NULL)
// 		exit(0);
// 	while ((file = readdir(dir)))
// 	{
// 		if ((get_type(file->d_type) == 'd'))
// 		{
// 			if ((ft_strcmp(file->d_name, "..")) && (ft_strcmp(file->d_name, ".")))
// 			{
// 			// closedir(d);
// 			path = ft_strjoin(d, "/");
// 			path = ft_strjoin(path, file->d_name);
// 			ft_printf("[%s]", path);
// 			stock_r(lst, f, path);
// 			}
// 		}
// 		// ft_putstr(file->d_name);
// 		// ft_putstr("\n");
// 	}
// 		ft_putstr("\n");

// }

// void		ls_r(t_flags f, char *d)
// {
// 	t_ls *lst;
// 	if(!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))
// 		exit (0);
// 	DIR *dir;
// 	dir = opendir(d);
// 	t_dir *file;

// 	file = NULL;
// 	while ((file = readdir(dir)))
// 	{
// 		if ((get_type(file->d_type) == 'd'))
// 			if ((ft_strcmp(file->d_name, "..")) && (ft_strcmp(file->d_name, ".")))
// 					{
// 						ft_printf("%s/%s:\n", d, file->d_name);
// 						stock_r(lst, f, file->d_name);
// 						closedir(file->d_name);
// 					}
// 	}
// }

			// if ((ft_strcmp(file->d_name, "..")) && (ft_strcmp(file->d_name, ".")))

char 	*rec_dir(char *d, char *new)
{
	char *tmp;

	tmp = ft_strjoin(d, "/");
	tmp = ft_strjoin(tmp, new);
	ft_printf("---------- %s ---------\n", tmp);
	return(tmp);

}

int 	check_dir(t_dir *file, char *d)
{

	if (get_type(file->d_type) == 'd' && (ft_strcmp(file->d_name, "..") && (ft_strcmp(file->d_name, "."))))
					return(1);
					// ft_printf("[%s]\n", file->d_name);
	return(0);
}

static void		display_r(t_flags f, t_dir *file, char *d)
{
(void)f;
	DIR *dir;
	// d = ft_strjoin(d, "/");
	// d = ft_strjoin(d, file->d_name);
	// ft_printf("[[[[[[[%s]]]]]]]\n\n", d);
	if (dir = opendir(d))
	{
while ((file = readdir(dir)))
{
	if (check_dir(file, d))
	{
		ft_printf("[%s]\n", file->d_name);
		display_r(f, file, rec_dir(d, file->d_name));
	}
}
	// ft_printf("-> [ %d ] <-\n", check_dir(file, d));
	// while(())
}

}

static void		ls_r(t_flags f, char *d)
{
	t_ls *lst;
	DIR  *dir;
	t_dir *file;
	if (!(lst = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit(0);
	if (dir = opendir(d))
				display_r(f, file, d);// ft_printf("[%s] \n", file->d_name);
	// while ((file = readdir(dir)))
		// {
			// if (get_type(file->d_type) == 'd')
		// }
		closedir(dir);
}

int			main()//int argc, char *argv[])
{
	int i;
	t_flags f;
	init_flags(&f);

	i = 1;
	ls_r(f, ".");
	// if (argc == 1)
	// 	ls_dir(".", f);
	// else
	// {
	// 	while (check_flags(argv[i], &f) && argv[i][0] == '-')
	// 				i++;
	// 	if (i == argc)
	// 		ls_dir(".", f);
	// 	while (i < argc)
	// 		print_dir(argv[i++], f);
	// }
	return(0);
}

