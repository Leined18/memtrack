/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:34:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:06:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_group     *ft_group_search(t_group *groups, const char *group_id)
{
    t_group	*current;

    if (!groups || !group_id)
        return (NULL);
    current = groups;
    while (current)
    {
        if (ft_strequ(current->id, group_id))
            return (current); // Retorna el grupo encontrado
        current = current->next; // Avanza al siguiente grupo
    }
    return (NULL); // Retorna NULL si no se encuentra el grupo
}