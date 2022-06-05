/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:29:08 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 16:58:27 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo *stock_in(int ac, char **av)
{
	t_philo	*a;
	int i;
	int n;

	i = 0;
	n = ft_atoi(av[1]);	
	a = malloc(sizeof(t_philo));
	a->ts = ft_atoi(av[4]);
	while (n > i)
	{
		a[i].p = ft_atoi(av[1]);
		a[i].td = ft_atoi(av[2]);
		a[i].te = ft_atoi(av[3]);
		if (ac == 6)
		a[i].tt = ft_atoi(av[5]);
		a[i].forks = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(a[i].forks, NULL);
		a[i].print_ = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(a[i].print_, NULL);
		a[i].threads = malloc(sizeof(pthread_t));
		a[i].index = i;
		i++;
	}
	return (a);
}
