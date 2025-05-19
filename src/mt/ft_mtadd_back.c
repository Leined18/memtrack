/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:17:09 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 12:36:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtaddback - Añade un nodo al final de la lista enlazada.
 * @node: Doble puntero al nodo a añadir.
 * @new_node: Doble puntero al nuevo nodo a añadir.
 * @backup: Doble puntero a la lista de backup. necesita ser inicializado. 
 *
 * Retorna 0 si se añade correctamente, -1 si no se puede añadir.
 */

int	ft_mtadd_back(t_mt **node, t_mt **new_node, t_backup **backup)
{
    t_mt	*current;

    if (!node || !new_node)
        return (-1);
    if (!*node)
    {
        *node = *new_node;
        return (0);
    }
    current = *node;
    while (current->next)
        current = current->next;
    if (current == *new_node)
        return (-1);
    current->next = *new_node;
    if (backup)
    {
        (*new_node)->backup = *backup;
        ft_backup_add(backup, *new_node);
    }
    return (0);
}
