/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtinsert_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:34:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 14:37:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos)
{
	t_mt	*current;
	t_mt	*mem;

	if (!list || !new_node || pos < 0)
		return ;
	current = *list;
	if (pos == 0)
	{
		ft_mtadd_front(list, new_node);
		mem = chaosmatrix(0, 0, 1);
		ft_mtadd_back(&mem, *list);
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
