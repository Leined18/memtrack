/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 07:17:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtpop(t_mt **lst)
{
	t_mt	*tmp;
	t_mt	*mem;

	if (!*lst)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	mem = chaosmatrix(0, 0, 1);
	ft_mtadd_back(&mem, ft_mtnew(tmp->data));
	free(tmp);
	tmp = NULL;
}
