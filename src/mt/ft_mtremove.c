/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:30:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 22:34:53 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtremove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 * return: if the node was removed successfully, otherwise returns 0.
 */

int	ft_mtremove(t_mt **head, t_mt *target, bool freec)
{
	t_mt *current;
	if (!head || !*head || !target)
		return 0;
	current = *head;
	while (current && current != target)
		current = current->next; // Busca el nodo objetivo
	if (!current)
		return 0; // Si no se encuentra el nodo, retorna 0
	if (current->prev)
		current->prev->next = current->next; // Desconecta el nodo de la lista
	else
		*head = current->next; // Si es el primer nodo, actualiza el head
	if (current->next)
		current->next->prev = current->prev; 
	if (freec)
		ft_mtfree(current); // Libera el nodo si freec es verdadero
	else
	{
		target->next = NULL; // Desconecta el nodo sin liberarlo
		target->prev = NULL;
	}
	return (1); // Retorna 1 si el nodo fue eliminado correctamente
}
