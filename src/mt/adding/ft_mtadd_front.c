/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:09:22 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 18:09:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Adds the element 'new'  of the list. FRONT direction.

void	ft_mtadd_front(t_mt **lst, t_mt *new)
{
	if (!lst || !new)
		return ;
	ft_mtadd(lst, new, FRONT);
}
