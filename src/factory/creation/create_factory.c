/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:42:28 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:29:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.h"

static void	init_actions(t_factory *factory)
{
	factory->actions[ORDER_NONE] = NULL;
	factory->actions[ORDER_BUILD] = NULL;
	factory->actions[ORDER_DESTROY_DATA] = destroy_box_data;
	factory->actions[ORDER_DESTROY_ALL] = destroy_all_builders;
	factory->actions[ORDER_UPDATE] = NULL;
	factory->actions[ORDER_GET] = get_box_builder;
	factory->actions[ORDER_VALIDATE] = NULL;
	factory->actions[ORDER_REPORT] = NULL;
}

t_factory	*create_factory(const char *id, t_builder *builder)
{
	t_factory	*factory;

	factory = (t_factory *)ft_calloc(1, sizeof(t_factory));
	if (!factory)
		return (NULL);
	factory->builder = builder;
	factory->id = builder->id;
	init_actions(factory);
	return (factory);
}
