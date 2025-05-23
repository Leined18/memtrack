/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:12 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/19 12:21:33 by danpalac         ###   ########.fr       */
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
	if (!node || !*node)
		return ;
	if ((*node)->next)
		ft_mtclear(&(*node)->next);
	if ((*node)->backup)
		ft_backup_remove(&(*node)->backup, *node);
	ft_mtdelete(*node);
	*node = NULL;
}
