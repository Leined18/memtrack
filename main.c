/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:09:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

bool filter(t_mt *node, t_data data)
{
	if (data.item)
	{
		if (ft_strncmp(data.label, "cmp", 3) == 0)
		{
			if (ft_strncmp(node->key, data.item, data.size) == 0)
				return (true);
		}
	}
	return (false);
}
int	main(void)
{
	t_mt		*node;
	t_backup	*backup;

	t_data	data;
	backup = NULL;
	data = ft_data_new(malloc(10), 10, "test", true);
	node = ft_mtnew("test", data, NULL, &backup);
	ft_mtaddlast(&node, ft_mtnew("test2", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test3", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test4", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test5", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test6", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test7", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	ft_mtaddlast(&node, ft_mtnew("test8", ft_data_new(malloc(95),0,0,true),NULL, &backup), 0.5, 2);
	
	if (ft_mtsearch(node, ft_data_new("test9", 5, "cmp", 0), filter))
	{
		ft_printf(GREEN "Node found\n" RESET);
	}
	else
	{
		ft_printf(RED "Node not found\n" RESET);
	}
	if (backup)
	{
		t_list *temp = backup->tracker;
		while (temp)
		{
			t_mt *mt = (t_mt *)temp->content;
			printf("Node key: %s\n", mt->key);
			temp = temp->next;
		}
		printf("Total nodes in backup: %zu\n", backup->item_count);
		ft_backup_free(&backup);
	}
	else
	{
		ft_printf(RED "Backup is NULL\n" RESET);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
