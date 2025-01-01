/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 12:23:44 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * match_clear - Libera la memoria de un nodo.
 * @node: Nodo a liberar.
 * @param: Parámetro adicional que se pasa a la función.
 */

static void	match_clear(t_mt *node, void *param)
{
	(void)param;
	if (!node)
		return ;
	if (node->values.to_free)
	{
		if (node->free_data && node->data)
			node->free_data(&node->data);
	}
	if (node->key)
		free(node->key);
	free_null((void **)&node);
}

/**
 * ft_mtclear - Libera la memoria de la lista.
 * @lst: Lista a liberar.
 * usa ft_mtiter para liberar la memoria de la lista
 */

void	ft_mtclear(t_mt **lst)
{
	if (!*lst || !lst)
		return ;
	ft_mtiter(*lst, NULL, match_clear);
	*lst = NULL;
}
