/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/06 17:33:15 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>


typedef struct s_philos
{
	int				p;
	int				td;
	int				te;
	int				ts;
	int				tt;
	int				lock;
	long int		time;
	pthread_mutex_t	print_;
}	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				index;
	int				is_l;
	int				check;
	int				eat;
	t_table			*t;
	struct s_philo		*next;
}	t_philo;

int		ft_atoi(char *str);
//int		ft_int_checker(t_args	*a);
// int		ft_errord();
t_table		stock_in(int ac, char **av);
long int    ft_time(void);
void	ft_usleep(int n);
void	ft_print(char *str, t_philo *philo);
t_philo	*createt_node(int index, t_table *t);
void	addback(t_philo **list, t_philo *tmp, int i);

#endif