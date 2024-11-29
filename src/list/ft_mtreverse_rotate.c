/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:55:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 13:56:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Moves the last element of the list to the first position.
void	ft_mtreverse_rotate(t_mt **list)
{
	t_mt	*prev;
	t_mt	*last;

	if (!list || !*list || !(*list)->next) // Lista vacía o con un solo nodo
		return ;
	// Inicializar punteros
	prev = NULL;
	last = *list;
	// Recorrer hasta el último nodo
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	// Desconectar el último nodo
	prev->next = NULL;
	last->prev = NULL;
	last->next = *list;
	(*list)->prev = last;
	*list = last;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtreverse_rotate(&stacka);
// stacka = "sa" -> "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"
