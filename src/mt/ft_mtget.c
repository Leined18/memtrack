/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:01:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 11:59:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtget - Obtiene un nodo de la lista enlazada por su clave.
 * @key: Clave del nodo a buscar.
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_mtget(const char *key)
{
    t_mt		*node;
    t_backup	*backup;
    
    if (!key || !*key)
        return (NULL);
    backup = ft_backup_static(0, false, false);
    if (!backup || !backup->slots)
        return (NULL);
    node = backup->slots[ft_hash_str(key) % backup->slot_count];
    while (node)
    {
        if (ft_strequ(node->key, key))
            return (node);
        node = node->next;
    }
    return (NULL);
}
