/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:04:17 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 05:21:22 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_quit(void)
{
	ft_putstr_fd("ERROR", 2);
	exit(0);
}

static int	is_neg(int neg, int nbr)
{
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}

int			ft_atoi(const char *str)
{
	int			i;
	long int	nbr;
	int			neg;

	nbr = 0;
	i = 0;
	neg = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr *= 10;
		nbr += (int)(str[i] - '0');
		i++;
	}
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_quit();
	return (is_neg(neg, (int)nbr));
}
