/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtinsert_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:08:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Inserts the element 'new_node' at the position 'pos' of the list.
void	ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos)
{
	t_mt	*current;
	t_mt	*mem;

	if (!list || !new_node || pos < 0)
		return ;
	current = *list;
	if (pos == 0)
	{
		ft_mtadd_front(list, new_node); // 0 es el primer nodo. se sale de chaos
		mem = chaosmatrix(0, 0, 1); // llama la lista
		ft_mtadd_back(&mem, *list); // lo vuelve a añadir a chaos
			// se añade a la matrix para liberar la memoria
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
		current->next = new_node;
	}
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtinsert_index(&stacka, ft_mtnew("pi"), 3);
// stacka = "miau" -> "guau" -> "mu" -> "pi" -> "le" -> "asd" -> "ñe" -> "sa"