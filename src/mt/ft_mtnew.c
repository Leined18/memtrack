/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 18:10:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtnew - Crea un nuevo nodo de tipo t_mt.
 * @key: Clave del nodo.
 * @backup: Puntero a la estructura de backup donde se agregará el nodo.
 * si existe un backup, se agrega el nodo a la lista de seguimiento del backup.
 */


t_mt	*ft_mtnew(const char *key, const char *id)
{
	t_mt		*node;
	t_backup	*backup;
	
	if (!key)
		return (NULL);
	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	node->id = ft_strdup(id);
	if (!node->id)
		return (free(node->key), free(node), NULL);
	backup = ft_backup_static(0, false, false);
	if (backup)
		ft_backup_add(&backup, node);
	return (node);
}
