/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtlast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:01 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:58:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns the last element of the list.
t_mt	*ft_mtlast(t_mt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->vect.right)
		lst = lst->vect.right;
	return (lst);
}
