/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:01:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 19:45:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Deletes the first element of the list.
void	ft_mtpop(t_mt **lst)
{
	if (!*lst || !lst)
		return ;
	ft_mtfree(lst);
}
