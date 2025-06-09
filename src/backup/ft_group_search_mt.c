/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_search_mt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:07:07 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:11:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_group_search_mt - Busca un grupo en la lista de grupos por su ID.
 * @groups: Doble puntero a la lista de grupos.
 * @id: ID del grupo a buscar.
 *
 * Retorna el grupo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_group_search_mt(t_group *groups, const char *id)
{
    t_group	*group;
    t_track	*found;

    if (!groups || !id || ft_strlen(id) == 0)
        return (NULL); // Retorna NULL si no hay grupos o ID
    group = groups;
    while (group)
    {
        found = ft_track_search(group->head, id); // Busca en el tracker del grupo
        if (found)
            return (found->node); // Retorna el nodo encontrado si existe
        group = group->next; // Avanza al siguiente grupo
    }
    return (NULL); // Retorna NULL si no se encuentra el grupo
}
