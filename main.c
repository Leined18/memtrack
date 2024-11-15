/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 11:24:43 by danpalac         ###   ########.fr       */
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
	ft_mtpush_data_back(&stacka, "guau");
	ft_mtpush_data_back(&stacka, "mu");
	ft_mtpush_data_back(&stacka, "le");
	ft_mtpush_data_back(&stacka, "asd");
	ft_mtpush_data_back(&stacka, "ñe");
	ft_mtpush_data_back(&stacka, "sa");
	ft_mtpush_data_back(&stackb, "pi");
	ft_mtmigrate_back(ft_mtfind_cmp_ref(&stacka, "le", ft_strncmp, 2), &stackb);
	printf("stacka: %p\n", stacka);
	ft_mtprint(stacka, 1, "\n");
	printf("stackb: %p\n", stackb);
	ft_mtprint(stackb, 1, "\n");
	ft_mtprint(chaosmatrix(0, 0, 1), 0, " ");
	return (0);
}
