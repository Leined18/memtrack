/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_add_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:20:04 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:37:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_add_mt - Agrega un nodo a un slot.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @node: Puntero al nodo a agregar.
 *
 * Esta función agrega un nodo a un slot, asegurándose de que el slot exista
 * y que el nodo no esté ya presente en el slot.
 */

int ft_slot_add_mt(t_slot ***slots, size_t slot_count, t_mt *node)
{
    size_t hash;
    t_slot **slots_ptr;

    if (!slots || slot_count == 0 || !node || !node->group_id || !node->id)
        return (0); // Retorna 0 si los parámetros son inválidos

    hash = ft_hash(node) % slot_count; // Calcula el hash del nodo
    slots_ptr = *slots;
    ft_slot_add_botton(&slots_ptr[hash], ft_slot_new(node->id, node->group_id, node)); // Agrega el nodo al slot
    *slots = slots_ptr; // Actualiza el doble puntero para reflejar el cambio
    return (1); // Retorna 1 si el nodo se agregó correctamente al slot
}