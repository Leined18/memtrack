/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtinsert_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 10:28:46 by danpalac         ###   ########.fr       */
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
		ft_mtadd_front(list, new_node);
		return ;
	}
	while (pos > 1 && current)
	{
		current = current->next;
		pos--;
	}
	if (current)
	{
		new_node->next = current->next;
		new_node->prev = current;
		if (current->next)
			current->next->prev = new_node;
		current->next = new_node;
	}
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtinsert_index(&stacka, ft_mtnew("pi"), 3);
// stacka = "miau" -> "guau" -> "mu" -> "pi" -> "le" -> "asd" -> "ñe" -> "sa"