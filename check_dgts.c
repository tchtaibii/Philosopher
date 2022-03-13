/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dgts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:50:57 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/14 00:06:14 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_dgts_check2(char **str, int i, int j)
{
	if (str[i][0] == '+')
			j++;
	while (str[i][j])
	{
		if ((str[i][j] >= '0' && str[i][j] <= '9'))
			j++;
		else
			return (0);
	}
	return (1);
}

int	ft_dgts_check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_dgts_check2(str, i, 0))
			return (0);
		
		i++;
	}
	return (1);
}
