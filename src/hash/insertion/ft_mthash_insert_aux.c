/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_insert_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:50:14 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 09:30:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_insert_aux(t_hash_table *ht, const char *parent_key,
		const char *aux_key, void *data, t_data_type type)
{
	t_mt	*parent;
	t_mt	*aux;

	if (!ht || !parent_key || !aux_key)
		return ;
	if (ft_mthash_exists(ht, parent_key))
	{
		parent = ft_mthash_find_node(ht, parent_key);
		if (ft_mtexists_mt(parent, aux_key))
		{
			aux = ft_mtsearch_key(parent, aux_key);
			ft_replace_data(aux, data, type);
			return ;
		}
		ft_mtaddlast_aux(parent, ft_mtnew(aux_key, data, type));
		return ;
	}
	ft_mthash_insert(ht, parent_key, NULL, NONE);
	ft_mthash_insert_aux(ht, parent_key, aux_key, data, type);
}
