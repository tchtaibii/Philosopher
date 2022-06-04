/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/04 23:57:06 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t *threads;
	pthread_mutex_t	forks;
	int		index;
}	t_philo;

typedef struct s_philos
{
	int		p;
	int		td;
	int		te;
	int		ts;
	int		tt;
}	t_philos;

int		ft_atoi(char *str);
//int		ft_int_checker(t_args	*a);
int		ft_errord();
t_philo	*philo_data(int n);
t_philos *stock_in(int ac, char **av);

#endif