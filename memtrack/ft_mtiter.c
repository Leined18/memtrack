/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 09:11:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "memtrack.h"

void	ft_mtiter(t_mt *lst, void (*f)(void *))
{
    while (lst)
    {
        f(lst->data);
        lst = lst->next;
    }
}
