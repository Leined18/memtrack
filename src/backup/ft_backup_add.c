/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:14:23 by danpalac         ###   ########.fr       */
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
	t_list *new;

	if (!backup || !node)
		return ;
	new = ft_lstnew(node);
	if (!new)
		return ;
	ft_lstadd_back(&(*backup)->tracker, new);
	(*backup)->item_count++;
}
