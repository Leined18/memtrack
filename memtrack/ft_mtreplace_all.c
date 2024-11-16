/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/16 11:11:25 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Replaces the list 'lst' with the list 'replace'.
void	ft_mtreplace_all(t_mt **lst, t_mt **replace)
{
	t_mt	*tmp;

	tmp = *replace;
	while (*lst)
		ft_mtpop(lst);
	*lst = tmp;
	*replace = NULL;
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// stackb = "pi"
// ft_mtreplace(&stacka, &stackb); // reemplaza stacka por stackb
// stacka = "pi"
// stackb = NULL
