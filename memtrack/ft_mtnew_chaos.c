/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtnew_chaos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:51:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/11/15 07:11:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

//Create a new node for a list including it in the chaos list.
//It's not possible to use ft_mtnew because it uses malloc and because of that
//it is not posible freeing it wit chaos. Also because if you change ft_mtnew
//so that it use chaosmatrix you enter in a infinite blucle.
t_mt	*ft_mtnew_chaos(void *data)
{
	t_mt	*new;

	//new = (t_mt *)malloc(sizeof(t_mt)); //El Cambio
	new = chaosmatrix(1, sizeof(t_mt), 0);
	if (!new)
		return (NULL);
	new->data = data;
	new->size = 0;
    new->count = 0;
	new->next = NULL;
	return (new);
}
