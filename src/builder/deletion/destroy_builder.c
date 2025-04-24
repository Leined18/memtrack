/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:03:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:03:42 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int	destroy_builder(t_builder **builder, t_box **box, void *arg, const char *id)
{
	t_box *current;

	if (!builder || !*builder)
		return (0);
	if (box && *box)
	{
		(*box)->destroy(*box);
		*box = NULL;
	}
	if ((*builder)->box)
	{
		current = (*builder)->box;
		while (current)
		{
			current->destroy(current);
			current = current->next;
		}
	}
	free_null((void **)builder);
	return (1);
}