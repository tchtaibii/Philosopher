/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 03:56:59 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *x)
{
	t_philo *philo;

	philo = (t_philo *)x;
	while (1)
	{
		printf("i'm the philosopher : %d\n",philo->index);
	}
	return NULL;
}

void	threads_mk(t_philo *philo)
{
	int	i;

	i = -1;
	printf("%d\n", philo->philos_->p);
	while (++i < philo->philos_->p)
	{
		pthread_create(philo[i].threads, NULL, &routine, (void *) &philo[i]);
	}
}

int	main(int ac, char **av)
{
	t_philos	*philos;
	t_philo		*philo;

	if (ac == 6 || ac == 5)
	{
		philos = stock_in(ac, av);
		philo = philo_data(philos);
		threads_mk(philo);
	}
	else
		write(2, "Error Args\n", 11);
}
