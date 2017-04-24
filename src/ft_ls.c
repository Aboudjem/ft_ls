#include "ft_ls.h"


void		ls_simple(void)
{
	DIR *dir;

	dir = opendir(".");
	readdir(dir);
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
