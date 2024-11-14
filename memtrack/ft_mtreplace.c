/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtreplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:01:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 18:01:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtreplace(t_mt **lst, t_mt **replace)
{
	t_mt *tmp;

	tmp = *replace;
	while (*lst)
		ft_mtpop(lst);
	*lst = tmp;
	*replace = NULL;
}
