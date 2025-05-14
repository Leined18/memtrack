/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:20:05 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:18:22 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Creates a new node for a list.
t_mt	*ft_mtnew(const char *key, t_data data, void (*free_ft)(t_data *), t_list **backup)
{
	t_mt	*node;
	
	node = ft_calloc(1, sizeof(t_mt));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	if (!node->key)
		return (free(node), NULL);
	node->data = data;
	node->data.free = free_ft;
	node->links = NULL;
	ft_mtbackup(backup, node);
	node->backup = *backup;
	return (node);
}
