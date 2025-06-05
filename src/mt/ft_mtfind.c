/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:07:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 10:22:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

t_mt	*ft_mtfind(t_mt **head, t_mt *mt)
{
    if (!head || !*head || !mt)
        return (NULL);
    t_mt	*current = *head;
    while (current)
    {
        if (ft_strequ(current->key, mt->key))
            return (current);
        current = current->next;
    }
    return (NULL);

}

