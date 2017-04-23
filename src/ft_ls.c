#include "ft_ls.h"
void	print_flags(t_flags f)
{
	if (CHECK_BIT(f.bit, L))
		ft_putstr("[l]");
	if (CHECK_BIT(f.bit, A))
		ft_putstr("[a]");
	if (CHECK_BIT(f.bit, R))
		ft_putstr("[r]");
	if (CHECK_BIT(f.bit, T))
		ft_putstr("[t]");
	if (CHECK_BIT(f.bit, RR))
		ft_putstr("[R]");
}

void	check_flags(t_flags *f, char c)
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

int		checking(char *argv, t_flags *f)
{
	if (argv[0] == '-')
	{
		(argv++);
		while (*argv)
		{
			check_flags(f, *argv);
			(argv++);
		}
		return (1);
	}
	return(0);
}

int			main(int argc, char *argv[])
{
	t_flags f;
	int i;
	
	i = 1;

		while (i < argc)
		{
			checking(argv[i], &f);
			i++;
		}
	print_flags(f);
	return(0);
}
