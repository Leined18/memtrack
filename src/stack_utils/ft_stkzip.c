/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkzip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:54:08 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/19 10:54:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stkzip(t_stack **stack)
{
	t_stack	*zip;
	t_mt	*zipdata;

	if (!(*stack) || !(*stack)->head)
		return (NULL);
	zip = ft_stknew(NULL, "zip");
	if (!zip)
		return (NULL);
	zipdata = ft_mtzip(&(*stack)->head);
	ft_mtpush(&zipdata, &zip->head);
	(*stack) = NULL;
	return (zip);
}
