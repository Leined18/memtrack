/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_insert_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:50:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 14:50:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static void	ft_mthash_insert_child(t_hash_table *ht, const char *parent_key,
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
		child = ft_mtnew(child_key, data, type);
		ft_mtadd_child(parent, child);
		return ;
	}
	ft_mtadd_child(ft_mtnew(parent_key, NULL, BRANCH), ft_mtnew(child_key, data,
			type));
}
