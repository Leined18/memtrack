/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/02 12:38:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtnew - Crea un nuevo nodo de tipo t_mt.
 * @key: Clave del nodo.
 */


t_mt	*ft_mtnew(const char *key)
{
	t_mt		*node;
	t_backup	*backup_temp;
	
	if (!key)
		return (NULL);
	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	backup_temp = ft_backup_static(0, false, false); // Obtiene el backup estático
	if (!backup_temp)
		return (free(node->key), free(node), NULL);
	ft_backup_add(backup_temp, node);
	return (node);
}
