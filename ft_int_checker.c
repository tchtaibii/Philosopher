/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:06:58 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/19 16:46:32 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_int_checker(t_args	*a)
{
	if (a->p <= 0)
		return (0);
	if (a->td <= 0)
		return (0);
	if (a->te <= 0)
		return (0);
	if (a->ts <= 0)
		return (0);
	else
		return (1);
}
