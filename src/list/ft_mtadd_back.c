/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:01:13 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 10:33:15 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new' at the end of the list.

void	ft_mtadd_back(t_mt **lst, t_mt *new)
{
    t_mt	*last;

    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = *lst;
    while (last->right)
        last = last->right;
    last->right = new;
	new->left = last;
	new->right = NULL;
}
