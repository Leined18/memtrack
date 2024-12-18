/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:58:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtswap(t_mt **list)
{
	t_mt	*tmp;
	// Si la lista es vacía o solo tiene un elemento,
	//no hay nada que intercambiar
	if (!list || !*list || !(*list)->vect.right)
		return ;
	// Intercambiamos los dos primeros nodos
	tmp = (*list)->vect.right;
	(*list)->vect.right = tmp->vect.right;
	if (tmp->vect.right)
		tmp->vect.right->vect.left = *list;
	tmp->vect.right = *list;
	(*list)->vect.left = tmp;
	tmp->vect.left = NULL;
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