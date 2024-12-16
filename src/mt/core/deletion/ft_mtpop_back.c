/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 10:52:34 by danpalac         ###   ########.fr       */
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
	while (tmp->right) // Vamos hasta el último nodo
		tmp = tmp->right;
	if (tmp->left)
		tmp->left->right = NULL;
	else
		*lst = NULL;
	ft_mtfree(tmp); // Liberamos el nodo eliminado
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_back(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"