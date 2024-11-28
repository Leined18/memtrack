/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_original_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:24:52 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 13:23:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtadd_key_prefix(char *prefix, t_mt *node)
{
	char	*new_key;

	if (!prefix || !node)
		return ;
	new_key = ft_strjoin(prefix, node->key);
	free(node->key);
	node->key = new_key;
}

void	ft_mtadd_key_suffix(char *suffix, t_mt *node)
{
	char	*new_key;

	if (!suffix || !node)
		return ;
	new_key = ft_strjoin(node->key, suffix);
	free(node->key);
	node->key = new_key;
}

char	*ft_mtnew_key(char *prefix, char *suffix)
{
	char	*new_key;

	if (!prefix || !suffix)
		return (NULL);
	new_key = ft_strjoin(prefix, suffix);
	return (new_key);
}

char	*ft_mtnew_original_key(char *key, t_mt *node)
{
	int		i;
	char	*new_key;
	char	*key_suffix;
	char	*tmp;

	if (!key || !node)
		return (NULL);
	new_key = ft_strdup(key);
	i = 1;
	while (ft_mtsearch_list(node, new_key, ft_mtcmp_key))
	{
		key_suffix = ft_itoa(i++);
		tmp = new_key;
		if (ft_strrchr(tmp, '-'))
		{
			if (ft_isdigit(*(ft_strrchr(tmp, '-') + 1)))
				*(ft_strrchr(tmp, '-')) = 0;
		}
		tmp = ft_straddc(tmp, '-');
		new_key = ft_mtnew_key(tmp, key_suffix);
		(free(tmp), free(key_suffix));
	}
	if (!ft_mtsearch_list(node, new_key, ft_mtcmp_key))
		return (free(key), new_key);
	return (NULL);
}
char	*ft_mthash_new_original_key(char *key, t_hash_table *ht)
{
	size_t	i;
	t_mt	*current;
	char	*tmp;

	if (!key || !ht)
		return (NULL);
	i = 0;
	while (i < ht->bucket_count)
	{
		current = ht->buckets[i];
		while (current)
		{
			tmp = ft_mtnew_original_key(key, current);
			if (tmp)
				return (tmp);
			current = current->next;
		}
	}
	return (NULL);
}
