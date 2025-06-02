/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 12:19:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"


/**
 * ft_backup_add - Agrega un nodo a la lista de seguimiento del backup.
 * @backup: Doble puntero a la estructura de backup.
 * @node: Puntero al nodo a agregar.
 * 
 */

void	ft_backup_add(t_backup *backup, t_mt *node)
{
	t_mt 	*new_node;
	t_track *track;
	
	if (!backup || !node)
		return ;
	node->backup = backup;
	new_node = node;
	track = ft_backup_new_track(node->key, new_node);
	if (!track)
		return ;
	ft_backup_add_track(backup, track);
	ft_backup_add_slot(backup, new_node);
	backup->item_count++;
}
