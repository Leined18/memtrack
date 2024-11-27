/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mthash_exists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:06:56 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 11:20:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mthash_exists(t_hash_table *ht, const char *key)
{
	t_mt *current;

	if (!ht || !key)
		return (0);
	current = ft_mthash_find_node(ht, key);
	if (!current)
		return (0);
	return (1);
}
