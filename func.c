/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:59:28 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/07 17:06:44 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long int	ft_time(void)
{
	long int		time;
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	time = ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
	return (time);
}

void	ft_usleep(int n)
{
	long int	c;
	long int	a;

	c = 0;
	a = ft_time();
	while (c < n)
	{
		c = ft_time() - a;
		usleep(100);
	}
}

void	ft_print(char *str, t_philo *philo)
{
	if (philo->t->lock && philo->t->p_eat && philo->is_l)
	{
		pthread_mutex_lock(&philo->t->print_);
		printf("%ld Philosopher %d %s \n", ft_time() - philo->t->time \
		, philo->index, str);
		pthread_mutex_unlock(&philo->t->print_);
	}
}

void	*routine(void *x)
{
	t_philo	*philo;

	philo = (t_philo *)x;
	while (philo->is_l)
	{
		if (philo->eat != philo->t->tt \
			&& philo->t->p_eat)
		{
			pthread_mutex_lock(&philo->fork);
			ft_print("took fork", philo);
			pthread_mutex_lock(&philo->next->fork);
			routine_norm1(philo);
			philo->check += ft_time() - philo->t->time;
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&philo->next->fork);
			philo->eat++;
			routine_norm2(philo);
		}
		if (philo->t->tt != -1)
			if (check_eat(philo))
				philo->t->p_eat = 0;
	}
	return (NULL);
}

int	check_eat(t_philo *philo)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < philo->t->p)
	{
		if (philo->eat == philo->t->tt)
			x++;
		philo = philo->next;
		i++;
	}
	if (x == philo->t->p)
		return (1);
	return (0);
}
