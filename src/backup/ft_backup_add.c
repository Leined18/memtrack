/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 20:03:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


/**
 * ft_backup_add - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 * 
 */

void	ft_backup_add(t_backup **backup, t_mt *node)
{	
	t_track *group;
	t_track *track;
	
	if (!backup || !*backup || !node)
		return ;
	if (!node->key || !node->id)
		return ;
	track = ft_track_new(node->key, node->id, node);
	group = ft_track_search((*backup)->tracker, node->key);
	if (group)
		ft_mtadd_back(&group->node, node);
	else 
		ft_backup_add_track(backup, track);
	ft_backup_add_slot(backup, track);
	(*backup)->item_count++;
}
