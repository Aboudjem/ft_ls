#include "ft_ls.h"

int             ft_len_int(int nbr)
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
