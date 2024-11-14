/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:16 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 08:28:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtprint(t_mt *lst, int b)
{
    while (lst && b)
    {
        printf("%p\n", (void *)lst->data);
        lst = lst->next;
    }
	while (lst && !b)
	{
		printf("%s\n", (char *)lst->data);
		lst = lst->next;
	}
}
