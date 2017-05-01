#include "ft_ls.h"

void	print_full(t_data d, size_t i)
{
	char *s;
	s = ft_strnew(i);
	ft_putstr(d.mod);
	ft_putstr("  ");
	if (ft_len_int((int)d.link) != 2)
		ft_putstr(" ");
	ft_putnbr((int)d.link);
	ft_putstr(" ");
	ft_putstr(d.user);
	ft_putstr("  ");
	ft_putstr(d.group);
	ft_memset(s, ' ', (i - (int)ft_len_int((int)d.size) + 2));
	ft_putstr(s);
	ft_putnbr((int)d.size);
	ft_putstr(" ");
	ft_putstr(d.time);
	ft_putstr(" ");
	ft_putstr(d.name);
}
