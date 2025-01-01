/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtmigrate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:15 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Migrates all the elements of the list src to the list dest in left.
void	ft_mtmigrate(t_mt **src, t_mt **dest)
{
	while (*src)
		ft_mtpush(src, dest);
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = ["pi"]

// ft_mtmigrate(&stacka, &stackb);
// stacka == NULL;
// stackb = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa" -> ["pi"]