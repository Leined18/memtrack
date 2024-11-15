/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 13:23:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// Moves the first element of the list to the last position.
void	ft_mtrotate(t_mt **list)
{
	t_mt *first;
	t_mt *last;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	last = *list;
	while (last->next)
		last = last->next; // Encuentra el último nodo
	*list = first->next;   // Avanza el inicio de la lista
	first->next = NULL;
	last->next = first; // Coloca el primer nodo al final
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtrotate(&stacka);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> "miau"