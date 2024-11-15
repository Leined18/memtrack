/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 19:19:35 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	main(void)
{
	t_mt	*stacka;
	t_mt	*stackb;
	t_mt	*tmp;

	stacka = NULL;
	stackb = NULL;
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	ft_mtpush_data(&stacka, "miau");
	ft_mtpush_data(&stacka, "guau");
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	ft_mterase(&stacka);
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	(void)stackb;
	ft_mtmigrate(&stacka, &stackb);
	ft_mtprint(stackb, 1, " -> ");
	tmp = (t_mt *)chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	chaosmatrix(0, 0, -1);
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	return (0);
}
