/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/13 14:12:23 by danpalac         ###   ########.fr       */
=======
/*   Updated: 2024/11/13 11:18:22 by danpalac         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtremove(t_mt **lst, t_mt *remove)
{
	t_mt	*tmp;

	if (*lst == remove)
	{
		tmp = (*lst)->next;
		ft_mtdel_data(&*lst);
		*lst = tmp;
		return ;
	}
	tmp = *lst;
	while (tmp->next != remove)
		tmp = tmp->next;
	tmp->next = remove->next;
	ft_mtdel_data(&remove);
	free(remove);
}
