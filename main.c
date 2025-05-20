/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/20 13:01:44 by danpalac         ###   ########.fr       */
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
	setter(ft_data_setter, (void **)&data, "%id%item%alloc%size%type%label%free",
			2, ft_split("l 2 2 s", ' '), true, sizeof(char *),
			4, "goodbye", free_2d);
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
	ft_data_free(data);
	return (0);
}
