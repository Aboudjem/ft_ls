#include "ft_ls.h"
static	int             ft_len_int(int nbr)
{
        int i;

        i = 0;
        if (nbr == 0)
                return (1);
        if (nbr < 0)
        {
                nbr = -nbr;
                i++;
        }
        while (nbr > 0)
        {
                nbr /= 10;
                i++;
        }
        return (i);
}

void	print_full(t_data d)
{
	ft_putstr(d.mod);
	ft_putstr("  ");
	if (ft_len_int((int)d.link) != 2)
		ft_putstr(" ");
	ft_putnbr(d.link);
	ft_putstr(" ");
	ft_putstr(d.user);
	ft_putstr("  ");
	ft_putstr(d.group);

}

  // char                    *mod;
  //       size_t                  link;
  //       char                    *user;
  //       char                    *group;
  //       long                    size;
  //       char                    *time;
  //       char                    *name;
  //       size_t                  t;