/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:17:15 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 11:17:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfirst(t_mt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->left)
		lst = lst->left;
	return (lst);
}

t_mt	*ft_mtfirst_parent(t_mt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->parent)
		lst = lst->parent;
	return (lst);
}
