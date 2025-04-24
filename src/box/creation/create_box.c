/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:56:23 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:11:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "box.h"

static void set_pointers(t_box *box)
{
	box->actions[ORDER_NONE] = NULL;
	box->actions[ORDER_GET] = NULL;
	box->actions[ORDER_DESTROY] = destroy_box;
	box->actions[ORDER_DESTROY_DATA] = destroy_box_data;
	box->actions[ORDER_VALIDATE] = NULL;
	box->actions[ORDER_UPDATE] = NULL;
	box->actions[ORDER_REPORT] = NULL;
	box->next = NULL;
}


t_box *create_box(const char *id, void *data, size_t size)
{
	t_box *box;

	box = (t_box *)ft_calloc(1, sizeof(t_box));
	if (!box)
		return (NULL);
	box->id = ft_strdup(id);
	if (!box->id)
	{
		free(box);
		return (NULL);
	}
	box->data = data;
	box->size = size;
	set_pointers(box);
	return (box);
}
