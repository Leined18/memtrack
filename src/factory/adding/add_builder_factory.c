/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_builder_factory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:44:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:26:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.h"

int	add_builder_factory(t_factory **factory, t_builder **builder, void *arg,
		const char *id)
{
	t_factory *current;

	if (!factory || !*factory || !builder || !*builder)
		return (0);
	if (!(*factory)->builders)
	{
		(*factory)->builders = *builder;
		return (1);
	}
	current = (*factory)->builders;
	while (current->next)
		current = current->next;
	current->next = *builder;
	(*builder)->next = NULL;
	*builder = NULL;
	return (1);
}