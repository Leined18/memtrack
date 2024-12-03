/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtexists_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:33:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:02:55 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns 1 if the node with the key 'key' exists in the list 'lst'.
int	ft_mtexists_mt(t_mt *root, const char *key)
{
	t_mt *current;

	if (!root || !key)
		return (0);
	current = ft_mtsearch_mt(root, key);
	if (!current)
		return (0);
	return (1);
}
