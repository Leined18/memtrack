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
void	ft_mtpoplast(t_mt **lst, t_direction direction)
{
	t_mt	*tmp;

	if (!*lst) // Si la lista está vacía, no hacemos nada
		return ;
	tmp = ft_mtlast(*lst, direction);
		// Obtenemos el último elemento de la lista
	ft_mtremove(lst, tmp);           
		// Eliminamos el último elemento de la lista
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_right(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"