/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backup_slot_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:02:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:18:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

static t_list	*ft_collect_all_nodes(t_mt **slots, size_t count)
{
	t_list	*all_nodes;
	t_mt	*curr;
	t_mt	*next;
	size_t	i;

	all_nodes = NULL;
	i = 0;
	while (i < count)
	{
		curr = slots[i];
		while (curr)
		{
			next = curr->next;
			curr->next = NULL;
			ft_lstadd_back(&all_nodes, ft_lstnew(curr));
			curr = next;
		}
		i++;
	}
	return (all_nodes);
}

static void	ft_rehash_all_nodes(t_backup *backup, t_list *all_nodes)
{
	t_list	*node;
	t_mt	*item;
	size_t	index;

	node = all_nodes;
	while (node)
	{
		item = (t_mt *)node->content;
		index = ft_hash_str(item->key) % backup->slot_count;
		item->next = backup->slots[index];
		backup->slots[index] = item;
		node = node->next;
	}
}

void	ft_backup_slot_update(t_backup **backup, size_t new_slot_count)
{
	t_list	*all_nodes;
	t_mt	**old_slots;
	size_t	old_count;

	if (!backup || !*backup || new_slot_count == 0)
		return ;
	old_slots = (*backup)->slots;
	old_count = (*backup)->slot_count;
	all_nodes = ft_collect_all_nodes(old_slots, old_count);
	free(old_slots);
	(*backup)->slots = ft_calloc(new_slot_count, sizeof(t_mt *));
	if (!(*backup)->slots)
	{
		ft_lstclear(&all_nodes, NULL);
		return ;
	}
	(*backup)->slot_count = new_slot_count;
	ft_rehash_all_nodes(*backup, all_nodes);
	ft_lstclear(&all_nodes, NULL);
}
