/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:13:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	free_element(void **element, void (*freec_func)(void *))
{
	if (element && *element)
	{
		if (freec_func)
			freec_func(*element);
		else
			free_null(element);
		*element = NULL;
	}
}

/**
 * ft_freec - Libera la memoria de un nodo t_mt.
 * @mt: Puntero al nodo a liberar.
 *
 * Esta función libera la memoria ocupada por el nodo t_mt y sus elementos
 * asociados.
 * Se asegura de liberar la clave, los datos y los enlaces del nodo.
 * esta tambien se usa en lstclear para liberar el tracker de backup.
 */

void	ft_mtfree(void *mt)
{
	t_mt	*node;
	t_backup	*backup;

	if (!mt)
		return ;
	node = (t_mt *)mt;
	if (node->backup)
	{
		backup = ft_backup_static(0, false, false);
		ft_backup_remove(&backup, node, true);
		return ;
	}
	if (node->key)
		free_element((void **)&node->key, NULL);
	if (node->data)
		free_element((void **)&node->data, node->data_free);
	if (node->addon)
		free_element((void **)&node->addon, node->addon_free);
	freec(node);
}
