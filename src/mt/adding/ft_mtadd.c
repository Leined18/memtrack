/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 16:06:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_cords	ft_cords_direction(t_cords cords, t_direction direction)
{
	if (direction == RIGHT)
		cords = ft_cords_diff(cords, 1, 0, 0);
	else if (direction == LEFT)
		cords = ft_cords_diff(cords, -1, 0, 0);
	else if (direction == UP)
		cords = ft_cords_diff(cords, 0, 1, 0);
	else if (direction == DOWN)
		cords = ft_cords_diff(cords, 0, -1, 0);
	else if (direction == FRONT)
		cords = ft_cords_diff(cords, 0, 0, 1);
	else if (direction == BACK)
		cords = ft_cords_diff(cords, 0, 0, -1);
	return (cords);
}

// Adds the element 'new' at the end of the list in whatever direction.
void	ft_mtadd(t_mt **lst, t_mt *new, t_direction direction)
{
	t_mt	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_mtlast(*lst, direction);
		last->vect[direction] = new;
		if (direction % 2 == 0)
			new->vect[(direction + 1) % 6] = last;
		else
			new->vect[(direction - 1) % 6] = last;
		new->cords = ft_cords_direction(last->cords, direction);
	}
}
