/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:37:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/09 23:53:19 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*ft_death_stock(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->t->p)
	{
		philo->is_l = 0;
		philo = philo->next;
		i++;
	}
	return (philo);
}

int	ft_death2(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->t->p)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
		i++;
	}
	pthread_mutex_destroy(&philo->t->print_);
	return (0);
}

int	ft_death(t_philo *philo)
{
	int	i;

	while (philo)
	{
		if (philo->check <= ft_time() - philo->t->time)
		{
			i = 0;
			philo->t->lock = 0;
			pthread_mutex_lock(&philo->t->print_);
			printf("\033[0;31m");
			if (philo->is_l)
				printf("%ld philo %d died \n"\
				, ft_time() - philo->t->time, philo->index);
			pthread_mutex_unlock(&philo->t->print_);
			philo = ft_death_stock(philo);
		}
		if (!philo->is_l || !philo->t->p_eat)
		{
			ft_death2(philo);
			return (0);
		}
		philo = philo->next;
	}
	return (1);
}
