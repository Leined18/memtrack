/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtinsert_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Inserts the element 'new_node' at the position 'pos' of the list.
void	ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos)
{
	t_mt	*current;

	if (!list || !new_node || pos < 0)
		return ;
	current = *list;
	if (pos > ft_mtsize(*list))
		pos = ft_mtsize(*list);
	if (pos == 0)
	{
		ft_mtadd_left(list, new_node);
		return ;
	}
	while (pos > 1 && current)
	{
		current = current->vect[RIGHT];
		pos--;
	}
	if (current)
	{
		new_node->vect[RIGHT] = current->vect[RIGHT];
		new_node->vect[LEFT] = current;
		if (current->vect[RIGHT])
			current->vect[RIGHT]->vect[LEFT] = new_node;
		current->vect[RIGHT] = new_node;
	}
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtinsert_index(&stacka, ft_mtnew("pi"), 3);
// stacka = "miau" -> "guau" -> "mu" -> "pi" -> "le" -> "asd" -> "ñe" -> "sa"