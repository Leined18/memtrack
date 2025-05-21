/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:16:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"




int	main(void)
{
	t_data	*data;

	data = constructor(c_data, "%id%item%alloc%size%type%label%free",
			1, ft_split("h 2 2 s", ' '), true, sizeof(char *),
			4, "greeting", free_2d);
	if (data)
	{
		printf("ID: %d\n", data->id);
		printf("Item: %p\n", (void *)data->item);
		printf("Alloc: %d\n", data->alloc);
		printf("Size: %zu\n", data->size);
		printf("Type: %d\n", data->type);
		printf("Label: %s\n", data->label);
	}
	else
	{
		printf("Error creating data structure.\n");
	}
	setter(set_data, (void **)&data, "%item%alloc%size%id%type%label%free",
			 ft_split("l 2 2 s", ' '), true, sizeof(char *),
			4,2, "goodbye  ", free_2d);
	if (data)
	{
		printf("\n----After Set-------------\nID: %d\n", data->id);
		printf("Item: %p\n", (void *)data->item);
		printf("Alloc: %d\n", data->alloc);
		printf("Size: %zu\n", data->size);
		printf("Type: %d\n", data->type);
		printf("Label: %s\n", data->label);
	}
	else
	{
		printf("Error creating data structure.\n");
	}
	t_mt *mt;

	mt = constructor(c_mt, "%id%key%data%size%type%label%free",
			1, "key");
	if (mt)
	{
		printf("ID: %d\n", mt->id);
		printf("Key: %s\n", (char *)mt->key);
	}
	else
	{
		printf("Error creating data structure.\n");
	}
	t_backup *backup = NULL;
	backup = ft_backup_new(0);
	setter(set_mt, (void **)&mt, "%key%backup%type%free%data", "newkey", backup,
		2, ft_data_free, data);
	backup->tracker = ft_backup_new_track("key", mt);
	if (mt)
	{
		printf("\n----------------\nMT ID: %d\n", mt->id);
		printf("MT Key: %s\n", (char *)mt->key);
		printf("Backup: %p\n", (void *)mt->backup);
		printf("Tracker: %p\n", (void *)backup->tracker);
		printf("Data: %p\n", (void *)mt->data);
		printf("Data ID: %d\n", ((t_data *)mt->data)->id);
		printf("Data Item: %p\n", (void *)((t_data *)mt->data)->item);
		printf("Data Alloc: %d\n", ((t_data *)mt->data)->alloc);
		printf("Data Size: %zu\n", ((t_data *)mt->data)->size);
		printf("Data Type: %d\n", ((t_data *)mt->data)->type);
	}
	else
	{
		printf("Error creating data structure.\n");
	}
	ft_backup_clear(&backup);
	return (0);
}
