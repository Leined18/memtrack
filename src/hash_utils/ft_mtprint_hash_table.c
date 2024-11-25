/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint_hash_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:29:11 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 18:33:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	print_inner_list(t_mt *inner_list)
{
	while (inner_list)
	{
		ft_printf(BLUE "{%s} -> " RESET, inner_list->key);
		inner_list = inner_list->next;
	}
	ft_printf(BLACK "NULL" RESET);
}

void	print_node(t_mt *node)
{
	if (!node)
		return ;
	ft_printf(YELLOW "(*) [%s]: " RESET, node->key);
	if (node->type == LIST)
		print_inner_list((t_mt *)node->data);
	else if (node->type == STRING)
		ft_printf(CYAN "\"%s\"" RESET, (char *)node->data);
	ft_printf("\n");
}

void	print_bucket(t_mt *bucket)
{
	ft_printf("\n");
	while (bucket)
	{
		print_node(bucket);
		bucket = bucket->next;
	}
}

void	ft_mtprint_hash_table(t_hash_table *ht)
{
	size_t	i;

	if (!ht)
		return ;
	i = 0;
	while (i < ht->bucket_count)
	{
		ft_printf(GREEN "->\tBucket %d\t<- \n" RESET, i);
		if (!ht->buckets[i])
			ft_printf(BLACK "NULL" RESET);
		else
			print_bucket(ht->buckets[i]);
		ft_printf("\n");
		i++;
	}
}
