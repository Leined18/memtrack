/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:15:43 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:52:36 by danpalac         ###   ########.fr       */
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
		lst = lst->vect.right;
	}
	return (size);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtsize(stacka); // 7
