/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_builder_factory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:45:27 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:45:31 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.h"

int	set_builder_factory(t_factory *factory, t_builder *builder)
{
	if (!factory || !builder)
		return (0);
	if (factory->builder)
	{
		factory->builder->destroy(factory->builder);
		factory->builder = NULL;
	}
	factory->builder = builder;
	return (1);
}