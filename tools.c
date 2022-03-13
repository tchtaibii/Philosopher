/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:39:00 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/14 00:08:33 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(char *str)
{
	long long		r;
	int				i;
	int				o;

	if (!str[0])
		ft_exit();
	i = 0;
	r = 0;
	o = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			o = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if ((r * o) > 2147483647 || (r * o) < -2147483648)
		ft_exit();
	return (o * r);
}
