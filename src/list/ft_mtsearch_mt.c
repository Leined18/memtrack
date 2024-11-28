/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 13:21:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*search_in_children(t_mt *parent, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	t_mt	*result;
	t_mt	*child;

	child = (t_mt *)parent->data;
	while (child)
	{
		// Si encontramos el nodo, lo devolvemos
		if (cmp(child, key))
			return (child);
		// Si no lo encontramos, buscamos en los hijos de este nodo
		if (child->type == BRANCH)
		{
			result = search_in_children(child, key, cmp);
			if (result)
				return (result);
		}
		child = child->next;
	}
	return (NULL);
}

// Busca un nodo en el árbol de la tabla hash
t_mt	*ft_mtsearch_mt(t_mt *root, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	if (!root || !key || !cmp)
		return (NULL);
	// Si el nodo raíz tiene la clave que estamos buscando
	if (cmp(root, key))
		return (root);
	if (root->type == BRANCH)
		return (search_in_children(root, key, cmp)); // Buscamos en los hijos
	return (NULL);                                  
		// Si no encontramos el nodo en ningún lado
}

t_mt *ft_mtsearch_list(t_mt *root, const char *key, int (*cmp)(t_mt *, const char *))
{
	t_mt *current;
	t_mt *result;

	if (!root || !key || !cmp)
		return (NULL);
	current = root;
	while (current)
	{
		result = ft_mtsearch_mt(current, key, cmp);
		if (result)
			return (result);
		current = current->next;
	}
	return (NULL);
}
