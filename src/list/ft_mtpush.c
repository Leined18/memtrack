/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 10:54:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list src to the list dest.
void	ft_mtpush(t_mt **src, t_mt **dest)
{
	t_mt	*node_to_move;

	if (!src || !*src) // Verificar si la lista src está vacía
		return ;
	// Extraer el nodo desde la cabecera de src
	node_to_move = *src;
	*src = (*src)->right;
	// Si hay más nodos en src, actualizar el puntero prev del nuevo primer nodo
	if (*src)
		(*src)->left = NULL;
	// Conectar el nodo movido con dest
	node_to_move->right = *dest;
	node_to_move->left = NULL;
	// Si dest no está vacío, actualizar el puntero prev del primer nodo de dest
	if (*dest)
		(*dest)->left = node_to_move;
	// Actualizar la cabecera de dest
	*dest = node_to_move;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]

// ft_mtpush(&stacka, &stackb);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "miau" -> ["pi"]
