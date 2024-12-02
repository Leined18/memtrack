/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:12:32 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:17:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// aplica la funcion que le envies a cada data de la lista.
void	ft_mtiter(t_mt *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->data);
		lst = lst->right;
	}
}
