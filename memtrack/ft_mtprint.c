/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 07:33:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtprint(t_mt *lst, int b, char *c)
{
	if (!lst)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	while (lst && b == 1)
	{
		ft_printf("%s%s", (char *)lst->data, c);
		lst = lst->next;
	}
	if (!b)
		ft_printf("\n");
	while (lst && !b)
	{
		ft_printf("%p%s", lst->data, c);
		lst = lst->next;
	}
	while (lst && b == 2)
	{
		ft_printf("%d%s", *(int *)lst->data, c);
		lst = lst->next;
	}
}

void	ft_mtprint_n(t_mt *lst, int b, char *c)
{
	if (!lst)
	{
		ft_printf("(NULL)\n");
		return ;
	}
	while (lst && b)
	{
		ft_printf("%d%s", lst->n, c);
		lst = lst->next;
	}
	if (!b)
		ft_printf("\n");
	while (lst && !b)
	{
		ft_printf("%d%s", lst->n, c);
		lst = lst->next;
	}
}
