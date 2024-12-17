/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:55:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/17 17:53:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static int	match_key(t_mt *node, void *key)
{
	return (ft_strncmp(node->key, key, ft_strlen(key)) == 0);
}

t_mt	*ft_mtsearch_key(t_mt *root, const char *key)
{
	t_mt	*result;

	if (!root || !key)
		return (NULL);
	result = ft_mtsearch(root, (void *)key, match_key);
	return (result);
}
