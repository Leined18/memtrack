/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 11:04:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int	ft_mtadd_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (parent->type != BRANCH)
		return (0); // Si el padre no es un nodo BRANCH, fallo.
	if (!parent->data)
	{
		parent->data = child;
		child->prev = NULL;
		child->next = NULL;
		return (1);
	}
	ft_mtadd_back((t_mt **)&parent->data, child);
	return (1);
}
