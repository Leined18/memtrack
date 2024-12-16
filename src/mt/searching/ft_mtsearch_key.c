/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:55:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/16 17:29:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtsearch_key(t_mt *root, const char *key)
{
	t_mt	*result;

	if (!root || !key)
		return (NULL);
	result = ft_mtsearch(root, (void *)key, match_key);
	return (result);
}
