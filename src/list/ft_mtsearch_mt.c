/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:02:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtsearch_mt(t_mt *root, const char *key)
{
	t_mt	*result;
	t_mt	*current;

	if (!root || !key)
		return (NULL);
	if (ft_mtcmp_key(root, key, ft_strlen(key)))
		return (root);
	current = root->children;
	while (current)
	{
		if (ft_mtcmp_key(current, key, ft_strlen(key)))
			return (current);
		if (current->children)
		{
			result = ft_mtsearch_mt(current, key);
			if (result)
				return (result);
		}
		current = current->right;
	}
	return (NULL);
}

t_mt	*ft_mtsearch_list(t_mt *root, const char *key)
{
	t_mt	*current;
	t_mt	*result;

	if (!root || !key)
		return (NULL);
	current = root;
	while (current)
	{
		result = ft_mtsearch_mt(current, key);
		if (result)
			return (result);
		current = current->right;
	}
	return (NULL);
}
