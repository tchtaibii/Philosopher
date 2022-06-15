/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/15 23:26:20 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*norm_thread(int i, t_philo *tmp, t_table table)
{
	while (++i < table.p)
	{
		tmp->eat = 0;
		tmp->check = tmp->t->td;
		pthread_create(&tmp->thread, NULL, &routine, (void *)tmp);
		pthread_detach(tmp->thread);
		if (tmp->t->p > 20)
			usleep(10);
		usleep(60);
		tmp = tmp->next;
	}
	return (tmp);
}

void	threads_mk(t_table table)
{
	int		i;
	t_philo	*tmp;
	t_philo	*philo;

	i = -1;
	philo = NULL;
	while (++i < table.p)
	{
		tmp = createt_node(i, &table);
		addback(&philo, tmp, i);
	}
	tmp = philo;
	i = -1;
	while (++i < table.p)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		tmp = tmp->next;
	}
	pthread_mutex_init(&tmp->t->print_, NULL);
	tmp->t->time = ft_time();
	tmp = norm_thread(-1, tmp, table);
	philo = tmp;
	while (1)
		if (!ft_death(philo))
			return ;
}

int	main(int ac, char **av)
{
	t_table		philo;

	if (ac == 6 || ac == 5)
	{
		philo = stock_in(ac, av);
		if (!ft_check_d(philo))
			return (0);
		threads_mk(philo);
	}
	else
		write(2, "Error Args\n", 11);
}
