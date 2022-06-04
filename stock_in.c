/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:29:08 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 00:09:20 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philos *stock_in(int ac, char **av)
{
	t_philos	*a;

	a = malloc(sizeof(t_philo));
	a->p = ft_atoi(av[1]);
	a->td = ft_atoi(av[2]);
	a->te = ft_atoi(av[3]);
	a->ts = ft_atoi(av[4]);
	if (ac == 6)
		a->tt = ft_atoi(av[5]);
	return (a);
}

t_philo	*philo_data(int n)
{
	t_philo *data;
	int i;

	data = malloc(n * sizeof(t_philo));
	i = 0;
	while (n > i)
	{
		pthread_mutex_init(&data[i].forks, NULL);
		data[i].index = i;
		i++;
	}
	return (data);
}
