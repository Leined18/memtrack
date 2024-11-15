/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 19:51:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	main(void)
{
	t_mt	*stacka;
	t_mt	*tmp;

	stacka = NULL;
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	ft_mtpush_data(&stacka, "miau");
	ft_mtpush_data(&stacka, "guau");
	ft_mtpush_data(&stacka, "mu");
	ft_mtpush_data(&stacka, "le");
	ft_mtpush_data(&stacka, "asd");
	ft_mtpush_data(&stacka, "ñe");
	ft_mtpush_data(&stacka, "sa");
	ft_mtprint(stacka, 1, " -> ");
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	chaosmatrix(-1, 0, 0);
	ft_mterase(&stacka);
	ft_mtprint(stacka, 1, " -> ");
	tmp = chaosmatrix(0, 0, 1);
	ft_mtprint(tmp, 0, " ");
	return (0);
}
