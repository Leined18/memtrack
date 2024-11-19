/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:16:13 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 10:23:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the beginning of the list.

void	ft_mtadd_front(t_mt **lst, t_mt *new)
{
	if (!lst || !new) // Verifica que los punteros sean válidos
		return ;
	new->next = *lst; // Haz que 'new' apunte al nodo actual
	new->prev = NULL; // 'new' es el primer nodo, por lo que su 'prev' es NULL
	if (*lst) // Si la lista no está vacía,
		(*lst)->prev = new;
	*lst = new; // Haz que la cabeza de la lista apunte a 'new'
}
