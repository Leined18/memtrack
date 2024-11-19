/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkmigrate_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:57:27 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:57:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stkmigrate_back(t_stack **src, t_stack **dest)
{
	if (!src || !(*src) || !(*src)->head)
		return ;
	ft_mtmigrate_back(&(*src)->head, &(*dest)->head);
	(*src)->tail = ft_mtlast((*src)->head);
	if ((*dest)->size == 0)
		(*dest)->tail = (*dest)->head;
	else
		(*dest)->tail = ft_mtlast((*dest)->head);
	(*src)->size = ft_mtsize((*src)->head);
	(*dest)->size = ft_mtsize((*dest)->head);
}
