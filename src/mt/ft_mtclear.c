/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:13:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtclear - Libera la memoria de mt usando la función de eliminación en backup
 * @node: Doble puntero a t_mt
 * 
 */

void	ft_mtclear(t_mt **node)
{
	t_list *backup;
	
	if (!node || !*node)
		return ;
	backup = (*node)->backup;
	ft_lstclear(&backup, ft_mtdelete);
	*node = NULL;
}
