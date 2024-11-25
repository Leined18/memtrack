/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 20:43:52 by danpalac         ###   ########.fr       */
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
		if (child->type == LIST)
		{
			result = search_in_children(child, key, cmp);
			if (result)
				return (result);
		}
		child = child->next;
	}
	return (NULL);
}

t_mt	*ft_mtsearch_mt(t_mt *root, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	if (!root || !key || !cmp)
		return (NULL);
	// Si el nodo raíz tiene la clave que estamos buscando
	if (cmp(root, key))
		return (root);
	if (root->type == LIST)
		return (search_in_children(root, key, cmp));
	return (NULL); // Si no encontramos el nodo en ningún lado
}
