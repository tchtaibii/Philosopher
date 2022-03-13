/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:04 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/14 00:08:42 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_args	*a;
	
	a = malloc(sizeof(t_args));
	if (ac == 6 || ac == 5)
	{
		if (!ft_dgts_check(av))
			ft_errord();
		a->p = ft_atoi(av[1]);
		a->td = ft_atoi(av[2]);
		a->te = ft_atoi(av[3]);
		a->ts = ft_atoi(av[4]);
		if (ac == 6)
			a->tt = ft_atoi(av[5]);
		
		
	}
	else
		write(2, "Error Args\n", 11);
}
