/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:35:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 12:14:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * @origin: Double pointer to the first node in the list.
 * @new: Pointer to the new node to be added.
 * @direction: Direction of the link (0.0 to 1.0).
 * @distance: Distance of the link.
 * 
 * @bid_link: Pointer to the bidirectional link.
 * 
 * Esta función agrega un nuevo link al final de la lista de links del nodo
 * origen y también agrega un link bidireccional al nuevo nodo.
 * Es una nueva forma de agregar nodos dependiendo de la direccion en radianes
 * y la distancia entre ellos.
 */
 
void	ft_mtadd_link(t_mt **origin, t_mt *new, t_offset offset, t_backup **backup)
{
	t_link		*link;
	t_link		*bid_link;
	t_mt		*last;

	if (!origin || !*origin || !new)
		return ;
	last = ft_mtlast(origin, false);
	if (!last)
		return ;
	link = ft_linknew(new, offset);
	if (!link)
		return ;
	bid_link = ft_linknew(last, ft_offset_inverse(offset));
	if (!bid_link)
	{
		free(link);
		return ;
	}
	link->key = new->key;
	ft_linkadd_first((t_link **)&last->links, link);
	ft_linkadd_first((t_link **)&new->links, bid_link);
	if (backup)
		ft_backup_add(backup, new);
}
	
	
