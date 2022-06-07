/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:29:08 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/07 03:21:30 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_table stock_in(int ac, char **av)
{
	t_table	a;

	a.p = ft_atoi(av[1], 1);
	a.td = ft_atoi(av[2], 1);
	a.te = ft_atoi(av[3], 1);
	a.ts = ft_atoi(av[4], 1);
	if (ac == 6)
		a.tt = ft_atoi(av[5], 0);
	else
		a.tt = -1;
	a.lock = 1;
	a.p_eat = 1;
	pthread_mutex_init(&a.print_, NULL);
	return (a);
}
