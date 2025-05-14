/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtbackup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:48:25 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 09:48:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Esta variable podría ser global o parte de tu sistema
// t_list *g_backup = NULL;

void	ft_mtbackup(t_list **backup, t_mt *node)
{
	t_list	*new;

	if (!backup || !node)
		return ;
	new = ft_lstnew(node);
	if (!new)
		return ;
	ft_lstadd_back(backup, new);
}
