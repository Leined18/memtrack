/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reference_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:10:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/04 17:27:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

 void	ft_mtupdate_ref(t_mt **ref, t_mt *node)
{
	int i;

	i = 0;
	if (*ref == node)
	{
		// Asignamos un nuevo nodo base si es posible
		while (i < MAX_DIRECTIONS)
		{
			if (node->vect[i])
			{
				*ref = node->vect[i];
				ft_mtupdate_cords(*ref, ft_mtcords(0, 0, 0));
				return ;
			}
			i++;
		}
		*ref = NULL; // No hay nodos restantes
	}
}
