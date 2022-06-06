/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/06 17:32:33 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long int    ft_time(void)
{
    long int        time;
    struct timeval    c_time;

    gettimeofday(&c_time, NULL);
    time = ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
    return (time);
}

void	ft_usleep(int n)
{
	long int c = 0;
	long int  a = ft_time();
	while (c < n)
	{
		c = ft_time() - a;
		usleep(100);
	}
}

void	ft_print(char *str, t_philo *philo)
{
	if (philo->t->lock)
	{
		pthread_mutex_lock(&philo->t->print_);
		printf("%ld Philosopher %d %s \n",ft_time() - philo->t->time, philo->index, str);
		pthread_mutex_unlock(&philo->t->print_);
	}
}

void	*routine(void *x)
{
	t_philo *philo;

	philo = (t_philo *)x;
	while (philo->is_l)
	{
		pthread_mutex_lock(&philo->fork);
		ft_print("took fork", philo);
		pthread_mutex_lock(&philo->next->fork);
		ft_print("took fork", philo);
		ft_print("is eating", philo);
		ft_usleep(philo->t->te);
		philo->check += ft_time() - philo->t->time;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_print("is sleeping", philo);
		ft_usleep(philo->t->ts);
		ft_print("is thinking", philo);
	}
	return NULL;
}

void	threads_mk(t_table table)
{
	int	i;
	t_philo	*tmp;
	t_philo *philo;

	i = 0;
	philo = NULL;
	while (i < table.p)
	{
		tmp = createt_node(i, &table);
		addback(&philo, tmp, i);
		i++;	
	}
	tmp = philo;
	i = 0;
	while (i < table.p)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		tmp = tmp->next;
		i++;	
	}
	pthread_mutex_init(&tmp->t->print_, NULL);
	tmp->t->time = ft_time();
	i = 0;
	while (i < table.p)
	{
		tmp->check = tmp->t->td;
		pthread_create(&tmp->thread, NULL, &routine, (void *)tmp);
		usleep(100);
		tmp = tmp->next;
		i++;
	}
	philo = tmp;
	while(1)
	{
		while (philo)
		{
			if (philo->check <= ft_time() - philo->t->time)
			{
				int i = 0;
				philo->t->lock = 0;
				pthread_mutex_lock(&philo->t->print_);
				printf("\033[0;31m");
				if (philo->is_l)
					printf("%ld philo %d died \n", ft_time() - philo->t->time, philo->index);
				pthread_mutex_unlock(&philo->t->print_);
				while (i < philo->t->p)
				{
					philo->is_l = 0;
					philo = philo->next;
					i++;
				}
				return ;
			}
			philo = philo->next;
		}
	}
}

int	main(int ac, char **av)
{
	t_table		philo;

	if (ac == 6 || ac == 5)
	{
		philo = stock_in(ac, av);
		threads_mk(philo);
	}
	else
		write(2, "Error Args\n", 11);
}
