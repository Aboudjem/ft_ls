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
		// if(get_type(file->d_type) == 'd')
		// 	printf("[%s]\n", path);
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
		ls_dir("./", f);
	else
	{
		while (check_flags(argv[i], &f) && argv[i][0] == '-')
					i++;
		if (i == argc)
			ls_dir("/", f);
		while (i < argc)
			print_dir(argv[i++], f);
	}
	return(0);
}

