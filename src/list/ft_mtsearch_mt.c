/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsearch_mt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:00:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtsearch_mt(t_mt *root, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	t_mt	*result;
	t_mt	*current;

	if (!root || !key || !cmp)
		return (NULL);
	if (cmp(root, key))
		return (root);
	current = root->children;
	while (current)
	{
		if (cmp(current, key))
			return (current);
		if (current->children)
		{
			result = ft_mtsearch_mt(current, key, cmp);
			if (result)
				return (result);
		}
		current = current->right;
	}
	return (NULL);
}

t_mt	*ft_mtsearch_list(t_mt *root, const char *key, int (*cmp)(t_mt *,
			const char *))
{
	t_mt	*current;
	t_mt	*result;

	if (!root || !key || !cmp)
		return (NULL);
	current = root;
	while (current)
	{
		result = ft_mtsearch_mt(current, key, cmp);
		if (result)
			return (result);
		current = current->right;
	}
	return (NULL);
}
