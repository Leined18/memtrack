/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:15:25 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/18 10:15:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the last element of the list.
void	ft_mtpop_back(t_mt **lst)
{
    t_mt	*tmp;
    t_mt	*gc;

    if (!*lst)
        return ;
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    if (tmp->prev)
        tmp->prev->next = NULL;
    gc = chaosmatrix(0, 0, 1);
    ft_mtpush_back(&tmp, &gc);
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtpop_back(&stacka);
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe"