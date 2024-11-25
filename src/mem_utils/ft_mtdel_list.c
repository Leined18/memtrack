/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtdel_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 18:14:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtdel_list(void **data)
{
	t_mt	*tmp;

	if (!data)
		return ;
	tmp = (t_mt *)*data;
	ft_mtclear(&tmp);
	*data = NULL;
}

