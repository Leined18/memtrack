/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 15:22:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	swap_connections(t_mt *node1, t_mt *node2)
{
	t_mt	*tmp;

	// Intercambiar los punteros "next" y "prev" de los nodos
	tmp = node1->next;
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = tmp;
	if (tmp)
		tmp->prev = node2;
	tmp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = tmp;
	if (node1->prev)
		node1->prev->next = node1;
	if (node2->prev)
		node2->prev->next = node2;
}

static void	swap_adjacent_nodes(t_mt *node1, t_mt *node2)
{
	// Caso 1: node1 está antes de node2
	if (node1->next == node2)
	{
		node1->next = node2->next;
		if (node2->next)
			node2->next->prev = node1;
		node2->next = node1;
		node2->prev = node1->prev;
		if (node1->prev)
			node1->prev->next = node2;
		node1->prev = node2;
	}
	// Caso 2: node2 está antes de node1
	else if (node2->next == node1)
	{
		node2->next = node1->next;
		if (node1->next)
			node1->next->prev = node2;
		node1->next = node2;
		node1->prev = node2->prev;
		if (node2->prev)
			node2->prev->next = node1;
		node2->prev = node1;
	}
}

void	ft_mtswap_nodes(t_mt **head, t_mt *node1, t_mt *node2)
{
	// Verificaciones previas
	if (!head || !node1 || !node2 || node1 == node2)
		return ;
	// Si los nodos son adyacentes, llamamos a la función para manejarlos
	if (node1->next == node2 || node2->next == node1)
	{
		swap_adjacent_nodes(node1, node2);
	}
	else // Si no son adyacentes, intercambiamos las conexiones
	{
		swap_connections(node1, node2);
	}
	// Actualizar la cabeza de la lista si es necesario
	if (*head == node1)
		*head = node2;
	else if (*head == node2)
		*head = node1;
}

void	ft_mtswap(t_mt **list)
{
	t_mt	*tmp;
	// Si la lista es vacía o solo tiene un elemento,
	//no hay nada que intercambiar
	if (!list || !*list || !(*list)->next)
		return ;
	// Intercambiamos los dos primeros nodos
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *list;
	tmp->next = *list;
	(*list)->prev = tmp;
	tmp->prev = NULL;
	*list = tmp;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtswap(&stacka);
// stacka = ["guau"] -> ("miau") -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"

// stacka = ["miau"] -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]

// ft_mtswap_nodes(*stacka, *stackb);
// stacka = ["pi"] -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["miau"]