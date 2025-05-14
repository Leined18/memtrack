/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:40:42 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 16:56:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtnew2 - Crea un nuevo nodo de tipo t_mt simple,
 * @key: Clave del nodo.
 * @data: Datos del nodo.
 * @backup: Doble puntero a la lista de backup. necesita ser inicializado.
 * 
 * siempre alloc es true
 */

t_mt	*ft_mtnew2(const char *key, void *item, t_backup **backup)
{
	t_mt *node;
	t_data data;

	if (!key || !backup)
		return (NULL);
	data = ft_data_new(item, 0, NULL, true);
	node = ft_mtnew(key, data, NULL, backup);
	if (!node)
		return (NULL);
	return (node);
}
