/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:03:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 11:18:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_stack	*ft_stknew(t_mt *lst)
{
	t_stack	*new;

	// Asignar memoria para la pila
	new = chaosmatrix(1, sizeof(t_stack), 0);
	if (!new)
		return (NULL);
	// Inicializar la pila con los valores pasados
	new->head = lst;
	new->tail = lst; // Si solo hay un nodo, la cabeza y la cola son el mismo
	new->size = 1;  
		// La pila tiene un tamaño inicial de 1 si se pasa un nodo inicial
	return (new);
}
