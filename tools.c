/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:39:00 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/16 01:48:13 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_other_check(t_table philo)
{
	if (philo.p > 200 || philo.p == 0)
	{
		printf("Philosophers must be 0 < and <= 200\n");
		return (0);
	}
	if (philo.td < 60)
	{
		printf("time to die must be > 60\n");
		return (0);
	}
	if (philo.te < 60)
	{
		printf("time to eat must be > 60\n");
		return (0);
	}
	if (philo.ts < 60)
	{
		printf("time to sleep must be > 60\n");
		return (0);
	}
	return (1);
}

int	ft_check_d(t_table philo)
{
	if (philo.p == -600)
		return (0);
	if (philo.td == -600)
		return (0);
	if (philo.te == -600)
		return (0);
	if (philo.ts == -600)
		return (0);
	if (philo.tt == 0 || philo.tt == -600)
		return (0);
	if (!ft_other_check(philo))
		return (0);
	return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	r;
	int				i;

	i = 0;
	r = 0;
	if (!ft_check(str))
	{
		printf("ERROR\n");
		return (-600);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	if (r >= 2147483648)
	{
		printf("ERROR\n");
		return (-600);
	}
	return (r);
}
