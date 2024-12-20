/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtadd_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:30:08 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 11:37:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtadd_aux(t_mt *node, t_mt *aux)
{
	if (!node || !aux)
		return ;
	if (node->aux)
		ft_mtadd_right(&node->aux, aux);
	else
		node->aux = aux;
}