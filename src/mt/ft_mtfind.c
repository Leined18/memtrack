/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:07:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:47:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfind(t_mt *node, t_mt *target)
{
    t_mt	*current;
    t_mt	*found;
    
    if (!node || !target)
        return (NULL); // Retorna NULL si alguno de los nodos es NULL o no tiene clave
    found = NULL;
    current = node;
    while (current)
    {
        if (current == target) // Verifica si el nodo actual es el mismo que el objetivo
        {
            found = current; // Encuentra el nodo con la misma clave
            break;
        }
        current = current->next; // Avanza al siguiente nodo
    }
    return (found); // Retorna el nodo encontrado o NULL si no se encuentra
}

