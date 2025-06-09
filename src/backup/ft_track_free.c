/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:36:14 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 19:54:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void ft_pointer_handle(t_track *pointer)
{
    t_mt *node;

    if (!pointer || !pointer->key)
        return;
    if (pointer)
    {
        node = pointer->node;
        if (node)
        {
            if (node->prev)
            {
                node->prev->next = node->next; // Desvincula el nodo previo
                pointer->node = node->prev; // Actualiza el nodo al previo
            }
            if (node->next)
            {
                node->next->prev = node->prev; // Desvincula el nodo siguiente
                pointer->node = node->next; // Actualiza el nodo al siguiente    
            }
            else 
                pointer->node = NULL; // Si no hay siguiente, pone el nodo a NULL
        }
    }
}

void	ft_track_free(t_track **track, bool free_node)
{
	t_track	*current;

	if (!track || !*track)
		return ;
	current = *track;

	// Romper la referencia cruzada con el "hermano"
	if (current->pointer)
		ft_pointer_handle(current->pointer);
	if (current->key)
		free(current->key);

	// Liberar nodo asociado si se pidió
	if (current->node && free_node)
		ft_mtfree(current->node);

	free(current);
	*track = NULL;
}
