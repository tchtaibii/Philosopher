/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 17:00:16 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*routine(void *x)
{
	t_philo *philo;

	philo = (t_philo *)x;
	while (1)
	{
		pthread_mutex_lock(philo[philo->index].forks);
		printf("Philosopher %d took fork\n",philo->index + 1);
		pthread_mutex_lock(philo[philo->index + 1].forks);
		printf("Philosopher %d took 2 fork\n",philo->index + 1);
		printf("Philosopher %d is eating\n", philo->index + 1);
		usleep(philo->te);
		printf("Philosopher %d is sleeping\n", philo->index + 1);
		usleep(philo->ts);
		pthread_mutex_unlock(philo->forks);
		pthread_mutex_unlock(philo[philo->index + 1].forks);
	}
	return NULL;
}

void	threads_mk(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->p)
	{
		pthread_create(philo[i].threads, NULL, &routine, &philo[i]);
		sleep(1);
	}
}

int	main(int ac, char **av)
{
	t_philo		*philo;

	if (ac == 6 || ac == 5)
	{
		philo = stock_in(ac, av);
		threads_mk(philo);
	}
	else
		write(2, "Error Args\n", 11);
}
