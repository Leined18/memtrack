/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 10:07:47 by danpalac         ###   ########.fr       */
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
	while (tmp->next) // Vamos hasta el último nodo
		tmp = tmp->next;
	if (tmp->prev) // Si el nodo anterior existe, lo actualizamos
		tmp->prev->next = NULL;
	else
		*lst = NULL;
	ft_mtfree(tmp); // Liberamos el nodo eliminado
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_back(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"