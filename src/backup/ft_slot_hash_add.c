/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_hash_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:51:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 22:43:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_slot_hash_add - Agrega un nodo a la lista de slots por su clave.
 * @slots: Doble puntero a la lista de slots.
 * @slot_count: Número de slots en la lista.
 * @node: Puntero al nodo a agregar.
 *
 * Retorna el slot encontrado o NULL si no se encuentra.
 */

void	ft_slot_hash_add(t_slot **slots, size_t slot_count, t_slot *node)
{
    size_t	hash;

    if (!slots || slot_count == 0 || !node)
        return ;
    hash = ft_hash_str(node->id) %  slot_count; // Calcula el hash del nodo usando su ID
    if (hash >= slot_count)
        return ; // Si el hash está fuera del rango, no se agrega
    if (!slots[hash])
        slots[hash] = node; // Si el slot está vacío, asigna el nuevo nodo
    else
        ft_slot_add_botton(&slots[hash], node); // Agrega el nodo al final del slot
}
