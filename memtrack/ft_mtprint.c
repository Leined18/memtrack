/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 13:17:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtprint(t_mt *lst, int b, char *c)
{
	if (!lst)
		return ;
	while (lst && b)
	{
		ft_printf("%s%s", (char *)lst->data, c);
		lst = lst->next;
	}
	if (b)
		ft_printf("\n");
	while (lst && !b)
	{
		ft_printf("%p%s", lst->data, c);
		lst = lst->next;
	}
}
