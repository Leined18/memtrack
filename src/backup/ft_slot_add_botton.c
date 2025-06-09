/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slot_add_botton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:08:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:47:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_slot_add_botton(t_slot **slot, t_slot *node)
{
    if (!slot || !node)
        return ;
    if (!*slot)
    {
        *slot = node; // Si el slot está vacío, asigna el nuevo nodo
        return ;
    }
    node->top = *slot; // Asigna el nodo actual como el nuevo nodo superior
    *slot = node; // Actualiza el slot para que apunte al nuevo nodo
}
