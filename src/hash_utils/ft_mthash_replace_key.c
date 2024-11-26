/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_replace_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:45:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 12:46:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mthash_replace_key(t_hash_table *ht, const char *old_key,
		const char *new_key)
{
	t_mt	*node;

	if (!ht || !old_key || !new_key)
		return ;
	node = ft_mthash_find_node(ht, old_key);
	if (!node)
		return ;
	free(node->key);
	node->key = ft_strdup(new_key);
}
