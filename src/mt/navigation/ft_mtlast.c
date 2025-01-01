/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:01 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:04:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns the last element of the list.
t_mt	*ft_mtlast(t_mt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->vect[RIGHT])
		lst = lst->vect[RIGHT];
	return (lst);
}
