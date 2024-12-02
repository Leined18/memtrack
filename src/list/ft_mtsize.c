/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:15:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:01:06 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Returns the size of the list.
int	ft_mtsize(t_mt *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->right;
	}
	return (size);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtsize(stacka); // 7
