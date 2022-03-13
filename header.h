/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 23:26:14 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/03/14 00:02:17 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct args
{
	int	p;
	int	td;
	int	te;
	int	ts;
	int tt;
}	t_args;



int		ft_atoi(char *str);
int		ft_dgts_check(char **str);
void	ft_errord();

#endif