/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_system.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:31:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 19:34:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static t_sys_action	default_factory_actions(void)
{
	t_sys_action table[ORDER_COUNT] = {
		NULL,
		(t_sys_action)factory_build,
		(t_sys_action)factory_destroy,
		(t_sys_action)factory_update,
	};
	return (table[order]);
}

static t_sys_action	default_builder_actions(void)
{
	t_sys_action table[ORDER_COUNT] = {
		NULL,
		(t_sys_action)builder_build,
		(t_sys_action)builder_destroy,
		(t_sys_action)builder_update,
	};
	return (table[order]);
}

t_sys_strategy	*create_default_strategy(void)
{
	t_sys_strategy	*s;

	s = malloc(sizeof(t_sys_strategy));
	if (!s)
		return (NULL);
	s->get_factory_action = default_factory_actions;
	s->get_builder_action = default_builder_actions;
	return (s);
}

t_system	*create_system(int id, t_box *boxes, t_builder *builders,
		t_factory *factories)
{
	t_system *system;

	system = (t_system *)ft_calloc(1, sizeof(t_system));
	if (!system)
		return (NULL);
	system->id = id;
	system->boxes = boxes;
	system->builders = builders;
	system->factories = factories;
	system->box_count = 0;
	system->builder_count = 0;
	system->factory_count = 0;
	system->strategy = create_default_strategy();
	if (!system->strategy)
	{
		free(system);
		return (NULL);
	}
	return (system);
}