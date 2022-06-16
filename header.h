/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/16 01:49:32 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdatomic.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				p;
	int				td;
	int				te;
	int				ts;
	int				tt;
	long int		time;
	atomic_int		lock;
	atomic_int		p_eat;
	pthread_mutex_t	print_;
}	t_table;

typedef struct s_philo
{
	int					index;
	t_table				*t;
	pthread_t			thread;
	pthread_mutex_t		fork;
	atomic_int			is_l;
	atomic_int			check;
	atomic_int			eat;
	struct s_philo		*next;
}	t_philo;

unsigned int	ft_atoi(char *str);
long int		ft_time(void);
t_table			stock_in(int ac, char **av);
t_philo			*createt_node(int index, t_table *t);
t_philo			*ft_death_stock(t_philo *philo);
void			*routine(void *x);
void			ft_usleep(int n);
void			ft_print(char *str, t_philo *philo);
void			routine_norm1(t_philo *philo);
void			routine_norm2(t_philo *philo);
void			addback(t_philo **list, t_philo *tmp, int i);
int				check_eat(t_philo *philo);
int				ft_check_d(t_table philo);
int				ft_death(t_philo *philo);
int				ft_death2(t_philo *philo);
#endif