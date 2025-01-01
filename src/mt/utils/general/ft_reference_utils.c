/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reference_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:10:50 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:11:12 by danpalac         ###   ########.fr       */
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
		while (i < 6)
		{
			if (node->vect[i])
			{
				*ref = node->vect[i];
				return ;
			}
			i++;
		}
		*ref = NULL; // No hay nodos restantes
	}
}
