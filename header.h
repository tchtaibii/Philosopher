/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/07 03:23:09 by tchtaibi         ###   ########.fr       */
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
	int				p_eat;
	pthread_mutex_t	print_;
}	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	pthread_mutex_t		fork;
	int					index;
	int					is_l;
	int					check;
	int					eat;
	t_table				*t;
	struct s_philo		*next;
}	t_philo;

int			ft_atoi(char *str, int l);
t_table		stock_in(int ac, char **av);
long int	ft_time(void);
void		ft_usleep(int n);
void		ft_print(char *str, t_philo *philo);
t_philo		*createt_node(int index, t_table *t);
void		addback(t_philo **list, t_philo *tmp, int i);
int			check_eat(t_philo *philo);
int			ft_check_d(t_table philo);

#endif