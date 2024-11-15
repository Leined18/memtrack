/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:58:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:18:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Adds the element 'new' at the end of the list.
void	ft_mtpush_back(t_mt **src, t_mt **dest)
{
	t_mt	*node_to_move;
	t_mt	*current;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	node_to_move->next = NULL;
	if (!*dest)
	{
		*dest = node_to_move;
		return ;
	}
	current = *dest;
	while (current->next)
		current = current->next;
	current->next = node_to_move;
}

// stacka = "miau" "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "pi"
// ft_mtpush_back(&stacka, &stackb); mueve el primer elemento de src atras de dest.
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe"
// stackb = "pi" -> "miau"
