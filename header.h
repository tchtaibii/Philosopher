/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/05 03:48:29 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philos
{
	int		p;
	int		td;
	int		te;
	int		ts;
	int		tt;
}	t_philos;

typedef struct s_philo
{
	pthread_t *threads;
	pthread_mutex_t	forks;
	int		index;
	t_philos	*philos_;
}	t_philo;

int		ft_atoi(char *str);
//int		ft_int_checker(t_args	*a);
int		ft_errord();
t_philo	*philo_data(t_philos *philos);
t_philos *stock_in(int ac, char **av);

#endif