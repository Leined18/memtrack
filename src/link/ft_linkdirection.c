/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkdirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:59:16 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 12:00:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_linkdirection - Devuelve el link con esta dirección.
 * @links: Doble puntero a la lista de links.
 * @direction: Dirección del link.
 */

t_link	*ft_linkdirection(t_link **links, float direction)
{
	t_link	*link;

	if (!links || !*links)
		return (NULL);
	link = *links;
	while (link)
	{
		if (link->direction == direction)
			return (link);
		link = link->next;
	}
	return (NULL);
}
