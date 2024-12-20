/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:36:53 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 08:37:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void    ft_mtremove(t_mt **mt, t_mt *node_to_remove)
{
    t_mt    *node;

    if (!mt || !*mt || !node_to_remove)
        return ;
    node = ft_mtsub(mt, node_to_remove);
    if (node)
        ft_mtdelete(&node);
}