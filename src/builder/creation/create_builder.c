/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:58:18 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 22:56:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

static void	set_actions(t_builder *builder)
{
	builder->actions[ORDER_NONE] = NULL;
	builder->actions[ORDER_SET] = set_box_builder;
	builder->actions[ORDER_ADD] = add_box_builder;
	builder->actions[ORDER_GET] = get_box_builder;
	builder->actions[ORDER_DESTROY] = destroy_builder;
	builder->actions[ORDER_VALIDATE] = NULL;
	builder->actions[ORDER_UPDATE] = NULL;
	builder->actions[ORDER_REPORT] = NULL;
}

t_builder	*create_builder(const char *id, t_box *box)
{
	t_builder	*builder;

	builder = (t_builder *)ft_calloc(1, sizeof(t_builder));
	if (!builder)
		return (NULL);
	builder->id = id;
	builder->box = box;
	set_actions(builder);
	return (builder);
}
