/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:20:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:17:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_mt *ft_mtsearch_rec(t_mt *current, t_data data, bool (*filter)(t_mt *, t_data), t_list **visited)
{
	t_link *link;
	t_list *node_wrapper;

	if (!current || !filter)
		return (NULL);
	if (ft_lstfind(*visited, current))
		return (NULL);
	node_wrapper = ft_lstnew(current);
	ft_lstadd_back(visited, node_wrapper);
	if (filter(current, data))
		return (current);
	link = current->links;
	while (link)
	{
		t_mt *result = ft_mtsearch_rec(link->node, data, filter, visited);
		if (result)
			return (result);
		link = link->next;
	}
	return (NULL);
}


/**
 * ft_mtsearch - Busca un nodo en el grafo.
 * @start: Nodo de inicio.
 * @data: Datos de contexto para la búsqueda.
 * @filter: Función de filtro para comparar los nodos.
 */


t_mt *ft_mtsearch(t_mt *start, t_data data, bool (*filter)(t_mt *, t_data))
{
	t_list *visited = NULL;
	t_mt *result = ft_mtsearch_rec(start, data, filter, &visited);
	ft_lstclear(&visited, NULL);
	return (result);
}
