/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_builders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:53:00 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:23:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int destroy_all_builders(t_builder **builder, t_box **box, void *arg, const char *id)
{
	if (!builder || !*builder)
		return (0);
	if (box && *box)
	{
		(*box)->destroy(*box);
		*box = NULL;
	}
	while (*builder)
	{
		t_builder *next = (*builder)->next;
		destroy_builder(builder, box, arg, id);
		free_null(builder);
		*builder = next;
	}
	*builder = NULL;
	return (1);
}