/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/12 14:42:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtprint(t_mt *lst)
{
    while (lst)
    {
        printf("%p\n", (void *)*lst->data);
        lst = lst->next;
    }
}
