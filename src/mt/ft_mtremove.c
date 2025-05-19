/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:30:43 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 12:02:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtremove - Elimina un nodo de la lista enlazada.
 * @node: Puntero al nodo a eliminar.
 */

void	ft_mtremove(t_mt **head, t_mt *target)
{
	t_mt *cur = *head;
	t_mt *prev = NULL;

	while (cur)
	{
		if (cur == target)
		{
			if (prev)
				prev->next = cur->next;
			else
				*head = cur->next;
			break ;
		}
		prev = cur;
		cur = cur->next;
	}
}