/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 23:00:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_search - Busca un slot en la lista de slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @key: Clave del slot a buscar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

t_slot	*ft_slot_search(t_slot *slot, const char *key)
{
    t_slot	*found;

    
    if (!slot || !key)
        return (NULL); // Retorna NULL si el slot o la clave son NULL
    found = slot; // Comienza desde el primer nodo del slot
    while (found)
    {
        if (ft_strequ(found->id, key))
            return (found); // Retorna inmediatamente el slot encontrado
        found = found->top; // Avanza al siguiente nodo en el slot
    }
    return (NULL); // Retorna el slot encontrado o NULL si no se encuentra
}