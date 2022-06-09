/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:03:07 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/07 17:07:03 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	routine_norm1(t_philo *philo)
{
	ft_print("took fork", philo);
	ft_print("is eating", philo);
	ft_usleep(philo->t->te);
}

void	routine_norm2(t_philo *philo)
{
	ft_print("is sleeping", philo);
	ft_usleep(philo->t->ts);
	ft_print("is thinking", philo);
}
