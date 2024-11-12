/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:57:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 11:39:20 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

t_mt	*ft_mtfind_data(t_mt *lst, void *data)
{
    while (lst)
    {
        if (*(lst->data) == data)
            return (lst);
        lst = lst->next;
    }
    return (NULL);
}
