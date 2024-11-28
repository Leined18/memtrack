/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:46 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:11:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list to the last position.
void	ft_mtrotate(t_mt **list)
{
	t_mt	*first;
	t_mt	*last;

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