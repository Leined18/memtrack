/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:09:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:49:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtget - Obtiene un nodo de la lista enlazada por su clave.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_mtget(const char *key)
{
    t_backup	*backup;
    t_mt		*node;

    if (!key || ft_strlen(key) == 0)
        return (NULL);
    backup = ft_backup_static(0, false, false); // Obtiene el backup estático
    if (!backup)
        return (NULL);
    node = ft_backup_search(&backup, key); // Busca el nodo en el backup
    if (!node)
        return (NULL);
    return (node); // Retorna el nodo encontrado
}