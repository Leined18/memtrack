/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:11:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 23:05:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfirst(t_mt *lst)
{
	if (!lst)
		return (NULL);
	while (lst->vect[LEFT])
		lst = lst->vect[LEFT];
	return (lst);
}
