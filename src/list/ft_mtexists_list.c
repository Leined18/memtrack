/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexists_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:37:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:03:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns 1 if the node with the key 'key' exists in the list 'lst'.
int	ft_mtexists_list(t_mt *root, const char *key)
{
	t_mt	*current;

	if (!root || !key)
		return (0);
	current = ft_mtsearch_list(root, key);
	if (!current)
		return (0);
	return (1);
}
