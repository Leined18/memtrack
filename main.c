/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 17:24:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

int	main(void)
{
	t_mt	*stacka;
	t_mt	*stackb;

	stacka = NULL;
	stackb = NULL;
	ft_mtpush_data_back(&stacka, "miau");
	ft_mtpush_data_back(&stacka, "pi");
	ft_mtpush_data_back(&stacka, "mu");
	ft_mtpush_data_back(&stacka, "le");
	ft_mtpush_data_back(&stacka, "asd");
	ft_mtpush_data_back(&stacka, "pi");
	ft_mtpush_data_back(&stackb, "pi");
	ft_mtpush_data_back(&stackb, "po");
	ft_mtprint(stacka, 1, " ");
	ft_mtprint(stackb, 1, " ");
	ft_mtreplace(stacka, "pi", "po", ft_memcmp, 2);
	ft_mtprint(stacka, 1, " ");
	ft_mtprint(stackb, 1, " ");
	ft_mtreplace_all(&stacka, &stackb);
	ft_mtprint(stacka, 1, " ");
	ft_mtprint(stackb, 1, " ");
	return (0);
}
