/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:12:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtnew - Crea un nuevo nodo de tipo t_mt.
 * @key: Clave del nodo.
 * @data: Datos del nodo.
 * @free_func: Función de liberación de datos.
 * @backup: Doble puntero a la lista de backup. necesita ser inicializado. 
 */


t_mt	*ft_mtnew(const char *key, t_data data, void (*free_func)(t_data *), t_backup **backup)
{
	t_mt	*node;
	
	if (!key || !backup)
		return (NULL);
	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	node->data = data;
	if (free_func)
		node->data.free = free_func;
	if (!*backup)
		*backup = ft_backup_new(0);
	node->backup = *backup;
	ft_backup_add(&node->backup, node);
	return (node);
}
