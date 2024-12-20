/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtset_to_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:56:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtset_to_free(t_mt *mt, int to_free)
{
	t_mt	*current;

	if (!mt)
		return ;
	current = mt;
	while (current)
	{
		current->values.to_free = to_free;
		if (current->vect.down)
			ft_mtset_to_free(current->vect.down, to_free);
		current = current->vect.right;
	}
}
