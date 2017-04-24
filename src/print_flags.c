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