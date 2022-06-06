/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:17:28 by tchtaibi          #+#    #+#             */
/*   Updated: 2022/06/06 17:07:46 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*createt_node(int index, t_table *t)
{
	t_philo	*head;

	head = malloc(sizeof(t_philo));
	head->index = index + 1;
	head->next = head;
    head->t = t;
    head->is_l = 1;
	return (head);
}

void	addback(t_philo **list, t_philo *tmp, int i)
{
	t_philo	*tmp1;
    
    int x = 0;

	if (*list == NULL)
		*list = tmp;
	else
	{
		tmp1 = *list;
        while (x < i - 1)
        {
            tmp1 = tmp1->next;
            x++;
        }
        tmp1->next = tmp;
        tmp->next = *list; 
	}
}
