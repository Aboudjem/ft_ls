#include "ft_ls.h"

static void	set_flags(t_flags *f, char c)
{
	if (c == 'l')
		f->bit |= L;
	else if (c == 'a')
		f->bit |= A;
	else if (c == 'r')
		f->bit |= R;
	else if (c == 't')
		f->bit |= T;
	else if (c == 'R')
		f->bit |= RR;
	else
	{
		printf("ls: illegal option -- %c\n", c);
		printf("usage: ls [-lartR] [file ...]\n");
		exit (0);
	}
}

int		check_flags(char *argv, t_flags *f)
{
	int i;

	if (!argv)
		return(0);
	if (*(argv++) == '-')
		while (*argv)
			set_flags(f, *(argv++));
	i = f->bit;
	return (i != 0 ? 1 : 0);
}
