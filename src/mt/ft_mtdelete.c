/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdelete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 11:06:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtdelete - Libera la memoria de un nodo t_mt.
 * @mt: Puntero al nodo a liberar.
 *
 * Esta función libera la memoria ocupada por el nodo t_mt y sus elementos
 * asociados.
 * Se asegura de liberar la clave, los datos y los enlaces del nodo.
 * esta tambien se usa en lstclear para liberar el tracker de backup.
 */

void	ft_mtdelete(void *mt)
{
	t_mt *node;
	
	if (!mt)
		return ;
	node = (t_mt *)mt;
	if (node->key)
		free(node->key);
	if (node->data.free)
		node->data.free(&node->data);
	if (node->links)
		ft_mtclear_link(&node->links);
	if (node->aux)
		ft_mtclear(&node->aux);
	free(mt);
}
