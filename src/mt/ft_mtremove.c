/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:30:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 17:05:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtremove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 * return: if the node was removed successfully, otherwise returns 0.
 */

int	ft_mtremove(t_mt **head, t_mt *target, bool free)
{
	t_mt *current;
	if (!head || !*head || !target)
		return (0);
	current = ft_mtfind(*head, target); // Busca el nodo en la lista
	if (!current)
		return (0); // Si no se encuentra el nodo, retorna 0
	if (current->prev)
		current->prev->next = current->next; // Desconecta el nodo de la lista
	else
		*head = current->next; // Si es el primer nodo, actualiza el head
	if (current->next)
		current->next->prev = current->prev; 
	if (free)
		ft_mtfree(current); // Libera el nodo si free es verdadero
	else
	{
		target->next = NULL; // Desconecta el nodo sin liberarlo
		target->prev = NULL;
	}
	return (1); // Retorna 1 si el nodo fue eliminado correctamente
}
