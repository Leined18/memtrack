/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:05:18 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 16:06:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_search - Obtiene un slot de la lista de slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @key: Clave del slot a buscar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

t_track	*ft_slot_search(t_track **slots, size_t slot_count, const char *key)
{
    size_t	i;
    t_track	*found;

    if (!slots || slot_count == 0 || !key)
        return (NULL);
    i = 0;
    found = NULL;
    while (i < slot_count)
    {
        found = ft_track_search(slots[i], key);
        if (found)
            return (found); // Retorna el slot encontrado
        i++;
    }
    return (NULL);
}
