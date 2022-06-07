/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:39:00 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/07 16:58:30 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_d(t_table philo)
{
	if (philo.p == -400 || philo.p == -600)
		return (0);
	if (philo.td == -400 || philo.td == -600)
		return (0);
	if (philo.te == -400 || philo.te == -600)
		return (0);
	if (philo.ts == -400 || philo.ts == -600)
		return (0);
	if (philo.tt == -400 || philo.tt == -600)
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

int	ft_atoi(char *str, int l)
{
	int		r;
	int		i;

	i = 0;
	r = 0;
	if (!ft_check(str))
	{
		printf("IS NOT DIGIT\n");
		return (-600);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	if (l)
	{
		if (r == 0)
		{
			printf("ERROR\n");
			return (-400);
		}
	}
	return (r);
}
