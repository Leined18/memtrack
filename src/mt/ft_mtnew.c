/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/03 23:42:41 by daniel           ###   ########.fr       */
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
		return (freec(node), NULL);
	backup_temp = ft_backup_static(0, false, false); // Obtiene el backup estático
	if (!backup_temp)
		return (freec(node->key), freec(node), NULL);
	ft_backup_add(&backup_temp, node);
	return (node);
}
