/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:46:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 12:51:20 by danpalac         ###   ########.fr       */
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
	{
		if (type == BRANCH)
			ft_mtdel_list(&new_data);
		else
			ft_mtdel_data(&new_data);
		return ;
	}
	ft_replace(node, new_data, type);
}
