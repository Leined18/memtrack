/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 17:22:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

// imprime la lista de datos de la lista.
void	ft_mtprint(t_mt *lst, int b, char *c)
{
	if (!lst) // si la lista esta vacia
	{
		ft_printf("(NULL)\n");
		return ;
	}
	while (lst && b == 1) // b == 1 imprime strings
	{
		ft_printf("%s%s", (char *)lst->data, c);
		lst = lst->next;
	}
	while (lst && !b) // b == 0 imprime direcciones
	{
		ft_printf("%p%s", lst->data, c);
		lst = lst->next;
	}
	while (lst && b == 2) // b == 2 imprime enteros
	{
		ft_printf("%d%s", *(int *)lst->data, c);
		lst = lst->next;
	}
	printf("\n");
}
// en desarollo para imprimir enteros
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
