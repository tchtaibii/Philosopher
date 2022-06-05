/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:29:08 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 03:52:17 by tchtaibi         ###   ########.fr       */
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

t_philo	*philo_data(t_philos *philos)
{
	t_philo *philo;
	int i;

	philo = malloc(philos->p * sizeof(t_philo));
	i = 0;
	
	while (philos->p > i)
	{
		pthread_mutex_init(&philo[i].forks, NULL);
		philo[i].threads = malloc(sizeof(pthread_t));
		philo[i].index = i;
		i++;
	}
	philo->philos_ = philos;
	return (philo);
}