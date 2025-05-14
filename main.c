/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 12:27:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void free_data(t_data *data)
{
	if (data->alloc)
		free(data->data);
	data->data = NULL;
	data->size = 0;
	data->label = NULL;
	data->alloc = false;
}


int	main(void)
{
	t_mt	*node;
	t_list	*backup;

	t_data	data;
	backup = NULL;
	data = ft_data_new(malloc(10), 10, "test", true);
	node = ft_mtnew("test", data, free_data, &backup);
	ft_mtaddlast(&node, ft_mtnew("test2", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	ft_mtaddlast(&node, ft_mtnew("test3", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	ft_mtaddlast(&node, ft_mtnew("test4", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	ft_mtaddlast(&node, ft_mtnew("test5", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	ft_mtaddlast(&node, ft_mtnew("test6", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	ft_mtaddlast(&node, ft_mtnew("test7", ft_data_new(NULL,0,0,0), free_data, &backup), 0.5, 2.0);
	if (backup)
	{
		t_list *temp = backup;
		while (temp)
		{
			t_mt *mt = (t_mt *)temp->content;
			printf("Node key: %s\n", mt->key);
			temp = temp->next;
		}
		ft_lstclear(&backup, ft_mtdelete);
	}
	else
	{
		ft_printf(RED "Backup is NULL\n" RESET);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
