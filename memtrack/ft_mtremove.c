/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 11:08:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtremove(t_mt **lst, t_mt *remove)
{
    t_mt	*tmp;

    if (*lst == remove)
    {
        tmp = (*lst)->next;
        free(*lst);
        *lst = tmp;
        return ;
    }
    tmp = *lst;
    while (tmp->next != remove)
        tmp = tmp->next;
    tmp->next = remove->next;
    ft_mtdel_data(remove->data);
    free(remove);
}
