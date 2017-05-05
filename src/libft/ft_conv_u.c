/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 06:19:40 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/29 06:20:01 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	conv_u(t_conv *t)
{
	init(t);
	ft_putlnbr_fd(t->u, t->fd);
	t->len_return = ft_len_int(t->u);
}
