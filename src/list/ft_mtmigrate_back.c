/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtmigrate_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:01:18 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/27 20:18:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Migrates all the elements of the list src to the list dest back.
void	ft_mtmigrate_back(t_mt **src, t_mt **dest)
{
	if (!*src)
		return ;
	while (*src)
		ft_mtpush_back(src, dest);
}
// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "pi"

// ft_mtmigrate_back(&stacka, &stackb);
// stacka = NULL;
// stackb = "pi" -> "sa" -> "ñe" -> "asd" -> "le" -> "mu" -> "guau" -> "miau"