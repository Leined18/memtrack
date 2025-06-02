/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:30:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 14:19:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtremove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 */

void	ft_mtremove(t_mt **head, t_mt *target, bool free)
{
	if (!head || !*head || !target)
		return ;
	if (*head == target)
	{
		if (target->next)
			*head = target->next;
		else if (target->prev)
			*head = target->prev;
		else
			*head = NULL; // Si es el único nodo, se establece el head a NULL
	}
	if (target->prev)
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	if (free)
		ft_mtfree(target); // Libera el nodo si se solicita
	else
	{
		target->next = NULL; // Desconecta el nodo sin liberarlo
		target->prev = NULL;
	}
}
