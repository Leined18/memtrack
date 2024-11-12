/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 11:04:34 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpop(t_mt **lst, t_mt *remove)
{
    t_mt	*tmp;

    if (!lst || !remove)
        return ;
    if (*lst == remove)
    {
        *lst = remove->next;
        ft_mtdel_data(remove->data);
        free(remove);
        return ;
    }
    tmp = *lst;
    while (tmp->next != remove)
        tmp = tmp->next;
    tmp->next = remove->next;
    ft_mtdel_data(remove->data);
    free(remove);
}
