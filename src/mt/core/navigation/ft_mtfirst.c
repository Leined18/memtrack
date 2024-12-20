/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:11:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfirst(t_mt *lst) {
  if (!lst)
    return (NULL);
  while (lst->vect.left)
    lst = lst->vect.left;
  return (lst);
}
