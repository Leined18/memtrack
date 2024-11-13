/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:11:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 18:26:23 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

t_mt	*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)())
{
	if (!lst || !data || !cmp)
		return (NULL);
    while (lst)
    {
        if (cmp(lst->data, data) == 0)
            return (lst);
        lst = lst->next;
    }
    return (NULL);
}
