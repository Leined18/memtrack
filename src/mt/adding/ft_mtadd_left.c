/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtaddlast_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:16:13 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the beginning of the list.

void	ft_mtaddlast_left(t_mt **lst, t_mt *new)
{
	if (!lst || !new) // Verifica que los punteros sean válidos
		return ;
	ft_mtaddlast(lst, new, LEFT); // Añade el nuevo nodo a la izquierda
}
