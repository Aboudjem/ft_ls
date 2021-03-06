/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdig_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 02:04:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:04:40 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdig_str(char *ptr)
{
	unsigned int i;

	i = 0;
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (0);
		++i;
	}
	return (1);
}
