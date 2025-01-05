/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddfirst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:37:08 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/05 12:57:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the beginning of the list in whatever direction.

static void	ft_mtconnect_neighbours(t_mt *neighbours[MAX_DIRECTIONS], t_mt *new)
{
	t_mt	*neighbour;
	int		direction;

	direction = 0;
	while (direction < MAX_DIRECTIONS)
	{
		neighbour = neighbours[direction];
		if (neighbour)
		{
			ft_mtaddlast(&new, neighbour, direction);
		}
		direction++;
	}
}

static void	ft_mtget_neighbourds(t_mt *lst, t_mt *neighbours[MAX_DIRECTIONS],
		t_direction direction)
{
	int	i;

	i = 0;
	while (i < MAX_DIRECTIONS)
	{
		if (i != ft_mtoposite_direction(direction))
		{
			neighbours[i] = lst->vect[i];
			ft_mtdisconnect(lst, i);
		}
		i++;
	}
}

void	ft_mtaddfirst(t_mt **lst, t_mt *new, t_direction direction)
{
	t_mt	*neighbours[MAX_DIRECTIONS];

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_mtget_neighbourds(*lst, neighbours, direction);
		ft_mtaddlast(lst, new, direction);
		ft_mtconnect_neighbours(neighbours, new);
		ft_mtupdate_cords((*lst), (*lst)->cords);
		(*lst) = new;
	}
}
