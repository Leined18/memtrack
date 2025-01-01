/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtswap(t_mt **list)
{
	t_mt	*tmp;
	// Si la lista es vacía o solo tiene un elemento,
	//no hay nada que intercambiar
	if (!list || !*list || !(*list)->vect[RIGHT])
		return ;
	// Intercambiamos los dos primeros nodos
	tmp = (*list)->vect[RIGHT];
	(*list)->vect[RIGHT] = tmp->vect[RIGHT];
	if (tmp->vect[RIGHT])
		tmp->vect[RIGHT]->vect[LEFT] = *list;
	tmp->vect[RIGHT] = *list;
	(*list)->vect[LEFT] = tmp;
	tmp->vect[LEFT] = NULL;
	*list = tmp;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtswap(&stacka);
// stacka = ["guau"] -> ("miau") -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"

// stacka = ["miau"] -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]

// ft_mtswap_nodes(*stacka, *stackb);
// stacka = ["pi"] -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["miau"]