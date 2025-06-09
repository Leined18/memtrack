/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:33:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:54:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_group_add_back(t_group **groups, t_group *new_group)
{
    t_group *current;
    
    if (!groups  || !new_group)
        return ;
    if (!*groups)
    {
        *groups = new_group;
        return ;
    }
    current = *groups;
    while (current->next)
        current = current->next; // Avanza al siguiente grupo
    current->next = new_group; // Agrega el nuevo grupo al final de la lista
}
