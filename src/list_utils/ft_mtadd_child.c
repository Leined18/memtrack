/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:04:12 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 13:25:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// añade un hijo a un nodo de la tabla hash
int	ft_mtadd_child(t_mt *parent, t_mt *child)
{
	if (!parent || !child)
		return (0);
	if (parent->type != BRANCH)
		return (0);
	if (!parent->data) // si no tiene hijos, añadimos el hijo
	{
		parent->data = child;
		child->prev = NULL;
		child->next = NULL;
		return (1);
	}
	ft_mtadd_back((t_mt **)&parent->data, child); // si ya tiene hijos, añadimos al final
	return (1);
}
