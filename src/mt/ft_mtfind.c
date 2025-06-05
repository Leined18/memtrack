/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:07:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:07:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfind(const char *name)
{
    t_backup	*backup;
    t_mt		*node;

    if (!name || !*name)
        return (NULL);
    backup = ft_backup_static(0, false, false);
    if (!backup || !backup->slots)
        return (NULL);
    node = backup->slots[ft_hash(name) % backup->slot_count];
    while (node)
    {
        if (ft_strequ(node->name, name))
            return (node);
        node = node->next;
    }
    return (NULL);
}