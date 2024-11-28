/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 13:07:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash
int	ft_mtadd_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (parent->type != BRANCH)
		return (0);
	if (!parent->data)
	{
		parent->data = child;
		child->prev = NULL;
		child->next = NULL;
		return (1);
	}
	if (ft_mtsearch_mt((t_mt *)parent->data, child->key, ft_mtcmp_key))
		child->key = ft_mtnew_original_key(child->key, parent);
	ft_mtadd_back((t_mt **)&parent->data, child); // si ya tiene hijos,
	return (1);
}
