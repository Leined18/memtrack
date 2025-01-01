/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:21:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the last element of the list.
void	ft_mtpop_right(t_mt **lst)
{
	t_mt	*tmp;

	if (!*lst) // Si la lista está vacía, no hacemos nada
		return ;
	tmp = *lst;
	while (tmp->vect[RIGHT]) // Vamos hasta el último nodo
		tmp = tmp->vect[RIGHT];
	if (tmp->vect[LEFT])
		tmp->vect[LEFT]->vect[RIGHT] = NULL;
	else
		*lst = NULL;
	ft_mtdelete(&tmp); // Liberamos el nodo eliminado
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_right(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"