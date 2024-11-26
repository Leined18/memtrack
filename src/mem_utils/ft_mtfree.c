/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:57 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 13:14:52 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtfree(t_mt *mt)
{
	if (mt->type == BRANCH)
		ft_mtdel_list((void **)&mt);
	else if (mt->type == LEAF)
	{
		ft_mtdel_data((void **)&mt->key);
		ft_mtdel_data(&mt->data);
		free(mt);
	}
    else if (mt->type == HASH_TABLE)
        ft_mthash_table_free((void **)&mt);
}
