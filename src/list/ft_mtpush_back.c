/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:58:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 08:06:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list.
void	ft_mtpush_back(t_mt **src, t_mt **dest)
{
	t_mt	*node_to_move;
	t_mt	*current;

	if (!src || !*src) // Verificar si la fuente está vacía
		return ;
	// Extraer el nodo desde la fuente
	node_to_move = *src;
	*src = (*src)->next;
	if (*src) // Si hay más nodos en la fuente, actualizar su puntero prev
		(*src)->prev = NULL;
	node_to_move->next = NULL;
	node_to_move->prev = NULL;
	// Si la lista destino está vacía
	if (!*dest)
	{
		*dest = node_to_move; // Asignar el nodo como el primer elemento
		return ;
	}
	// Encontrar el último nodo en la lista destino
	current = *dest;
	while (current->next)
		current = current->next;
	// Insertar el nodo al final
	current->next = node_to_move;
	node_to_move->prev = current; // Actualizar el puntero prev del nodo movido
}

// stacka = "miau" "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "pi"
// ft_mtpush_back(&stacka,&stackb); mueve el primer elemento de src atras de dest.
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe"
// stackb = "pi" -> "miau"
