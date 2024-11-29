/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_insert_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:50:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 15:48:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_insert_child(t_hash_table *ht, const char *parent_key,
		const char *child_key, void *data, t_data_type type)
{
	t_mt	*parent;
	t_mt	*child;

	if (!ht || !parent_key || !child_key)
		return ;
	if (ft_mthash_exists(ht, parent_key))
	{
		parent = ft_mthash_find_node(ht, parent_key);
		if (ft_mtexists_mt(parent, child_key))
		{
			child = ft_mtsearch_mt(parent, child_key, ft_mtcmp_key);
			ft_replace(child, data, type);
			return ;
		}
		if (parent->type != BRANCH)
		{
			child = ft_mtdup(parent);
			(ft_replace(parent, NULL, BRANCH), ft_mtadd_child(parent, child));
		}
		ft_mtadd_child(parent, ft_mtnew(child_key, data, type));
		return ;
	}
	ft_mthash_insert(ht, parent_key, NULL, BRANCH);
	parent = ft_mthash_find_node(ht, parent_key);
	ft_mtadd_child(parent, ft_mtnew(child_key, data, type));
}
