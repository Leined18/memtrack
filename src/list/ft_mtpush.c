/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:54:06 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/12 14:35:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the first element of the list src to the list dest.
// Mueve el puntero *src al nodo izquierdo si existe
static void	move_src_to_left(t_mt **src, t_mt *node_to_move)
{
	t_mt	*prev;

	prev = node_to_move->left;
	if (prev)
	{
		*src = prev;
		prev->right = node_to_move->right;
		if (node_to_move->right)
			node_to_move->right->left = prev;
	}
	else
		*src = prev;
}

// Mueve el puntero *src al nodo derecho si no hay nodo izquierdo
static void	move_src_to_right(t_mt **src, t_mt *node_to_move)
{
	t_mt	*prev;

	prev = NULL;
	prev = node_to_move->left;
	*src = node_to_move->right;
	if (*src)
	{
		if (prev)
		{
			prev->right = *src;
			(*src)->left = prev;
		}
		else
			(*src)->left = NULL;
	}
}

// Desconecta el nodo de la lista de origen
static void	disconnect_node_from_src(t_mt **src, t_mt *node_to_move)
{
	t_mt	*prev;

	prev = node_to_move->left;
	if (prev)
		prev->right = node_to_move->right;
	if (*src == NULL && prev)
	{
		prev->right = NULL;
		*src = prev;
	}
}

// Conecta el nodo a la lista de destino
static void	connect_node_to_dest(t_mt **dest, t_mt *node_to_move)
{
	node_to_move->right = *dest;
	node_to_move->left = NULL;
	if (*dest)
		(*dest)->left = node_to_move;
	*dest = node_to_move;
}

// Función principal para mover el nodo de la lista src a la lista dest
void	ft_mtpush(t_mt **src, t_mt **dest)
{
	t_mt	*node_to_move;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	// Mover el puntero *src al nodo izquierdo si existe
	move_src_to_left(src, node_to_move);
	// Si no había nodo izquierdo, mover a la derecha
	if (!*src)
		move_src_to_right(src, node_to_move);
	// Desconectar el nodo de la lista de origen
	disconnect_node_from_src(src, node_to_move);
	// Conectar el nodo a la lista de destino
	connect_node_to_dest(dest, node_to_move);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]

// ft_mtpush(&stacka, &stackb);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "miau" -> ["pi"]
