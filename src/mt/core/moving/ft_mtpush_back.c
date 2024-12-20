/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:58:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:21:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list.
void	ft_mtpush_right(t_mt **src, t_mt **dest)
{
	t_mt	*node_to_move;
	t_mt	*current;

	if (!src || !*src) // Verificar si la fuente está vacía
		return ;
	// Extraer el nodo desde la fuente
	node_to_move = *src;
	*src = (*src)->vect.right;
	node_to_move = ft_mtdisconnect_horizontal(node_to_move);
	if (!*dest)
	{
		*dest = node_to_move; // Asignar el nodo como el primer elemento
		return ;
	}
	current = *dest;
	while (current->vect.right)
		current = current->vect.right;
	current->vect.right = node_to_move;
	node_to_move->vect.left = current;
}

// stacka = "miau" "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "pi"
// ft_mtpush_right(&stacka,&stackb); mueve el primer elemento de src atras de dest.
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe"
// stackb = "pi" -> "miau"
