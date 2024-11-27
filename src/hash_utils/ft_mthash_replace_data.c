/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 13:44:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_replace_data(t_hash_table *ht, const char *key,
		void *new_data, t_data_type type)
{
	t_mt	*node;

	if (!ht || !key || !new_data)
		return ;
	node = ft_mthash_find_node(ht, key);
	if (!node)
		return ;
	ft_mtdel_by_type(&node->data, node->type);
	ft_replace(node, new_data, type);
}