/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_box_builder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:10:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:10:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int	add_box_builder(t_builder **builder, t_box **box, void *arg, const char *id)
{
	t_box	*current;
	if (!builder || !*builder)
		return (0);
	if (!(*builder)->box)
	{
		(*builder)->box = *box;
		return (1);
	}
	current = (*builder)->box;
	while (current->next)
		current = current->next;
	current->next = *box;
	(*box)->next = NULL;
	(*box) = NULL;
	return (1);
}
