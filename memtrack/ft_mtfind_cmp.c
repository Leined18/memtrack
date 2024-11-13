/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:11:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 09:11:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

t_mt	*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)())
{
    while (lst)
    {
        if (cmp(lst->data, data) == 0)
            return (lst);
        lst = lst->next;
    }
    return (NULL);
}
