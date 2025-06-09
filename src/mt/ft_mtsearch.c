/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:01:51 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 17:08:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtsearch - Obtiene un nodo de la lista enlazada por su clave.
 * @key: Clave del nodo a buscar.
 * Retorna el nodo encontrado o NULL si no se encuentra.
 */

t_mt	*ft_mtsearch(t_mt *head, const char *key)
{
    t_mt	*current;

    if (!head || !key)
        return (NULL); // Retorna NULL si no hay cabeza o clave
    current = head;
    while (current)
    {
        if (ft_strequ(current->key, key))
            return (current); // Retorna el nodo encontrado
        current = current->next; // Avanza al siguiente nodo
    }
    return (NULL);
}
