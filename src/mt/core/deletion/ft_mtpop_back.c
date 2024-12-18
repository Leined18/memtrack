/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:55:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the last element of the list.
void	ft_mtpop_back(t_mt **lst)
{
	t_mt	*tmp;

	if (!*lst) // Si la lista está vacía, no hacemos nada
		return ;
	tmp = *lst;
	while (tmp->vect.right) // Vamos hasta el último nodo
		tmp = tmp->vect.right;
	if (tmp->vect.left)
		tmp->vect.left->vect.right = NULL;
	else
		*lst = NULL;
	ft_mtfree(tmp); // Liberamos el nodo eliminado
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_back(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"