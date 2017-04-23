/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:05:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:05:42 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long int	u_nbr;

	u_nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr((int)(u_nbr / 10));
	ft_putchar(u_nbr % 10 + '0');
}
