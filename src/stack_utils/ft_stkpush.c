/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:29:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 13:37:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkpush(t_stack **src, t_stack **dest)
{
	if (!src || !(*src) || !dest || !(*dest) || (*src)->size == 0)
		return ;
	ft_mtpush(&(*src)->head, &(*dest)->head);
	// Actualizar la cola de la pila fuente
	if ((*src)->size == 1) // Si solo queda un nodo, el tail será NULL
		(*src)->tail = NULL;
	else
		(*src)->tail = ft_mtlast((*src)->head);
	// Actualizar la cola de la pila destino
	if ((*dest)->size == 0) // Si era una pila vacía, el tail será el nuevo head
		(*dest)->tail = (*dest)->head;
	else
		(*dest)->tail = ft_mtlast((*dest)->head);
	// Actualizar tamaños
	(*src)->size = ft_mtsize((*src)->head);
	(*dest)->size = ft_mtsize((*dest)->head);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]
// ft_stkpush(stacka, stackb);
// stacka = "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "miau" -> ["pi"]
