/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 12:22:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @origin: Double pointer to the first node in the list.
 * @new: Pointer to the new node to be added.
 * @direction: Direction of the link (0.0 to 1.0).
 * @distance: Distance of the link.
 * 
 * Esta función agrega un nuevo link al final de la lista de links del nodo
 * origen y también agrega un link bidireccional al nuevo nodo.
 * Es una nueva forma de agregar nodos dependiendo de la direccion en radianes
 * y la distancia entre ellos.
 */
 
void	ft_mtaddlast(t_mt **origin, t_mt *new, float direction, float distance)
{
	t_link		*link;
	t_link		*bidirectional_link;
	t_mt		*last;

	if (!origin || !*origin || !new)
		return ;
	last = ft_mtlast(origin, direction, false);
	if (!last)
		return ;
	link = ft_linknew(new, direction, distance);
	if (!link)
		return ;
	bidirectional_link = ft_linknew(last, direction * -1, distance);
	if (!bidirectional_link)
	{
		free(link);
		return ;
	}
	new->backup = last->backup;
	ft_linkadd_last(&last->links, link);
	ft_linkadd_last(&new->links, bidirectional_link);
}
	
	
