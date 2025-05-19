/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:32:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 13:36:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_link_get - Obtiene un nodo de la lista enlazada.
 * @node: Doble puntero a la lista enlazada.
 * @key: Clave del nodo a buscar.
 * 
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */


t_link	*ft_link_get(t_link *node, const char *key)
{
    t_link	*cur;

    if (!node || !key)
        return (NULL);
    cur = node;
    while (cur)
    {
        if (cur->key && ft_strncmp(cur->key, key, ft_strlen(key)) == 0)
            return (cur);
        cur = cur->next;
    }
    return (NULL);
}