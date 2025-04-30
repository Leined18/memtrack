/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/30 16:09:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test(t_mt **node1)
{
	t_mt	*found;
	t_mt	*node;

	node = *node1;
	node = ft_mtnew("key1", "value1", NONE);
	if (!node)
		return (0);
	ft_mtaddlast(&node, ft_mtnew("key2", "value2", NONE), DOWN);
	ft_mtaddlast(&node, ft_mtnew("key3", "value3", NONE), UP);
	ft_mtaddlast_aux(node, ft_mtnew("key9", "value9", NONE));
	ft_mtaddlast_aux(node, ft_mtnew("key10", "value10", NONE));
	ft_mtrotate(&node, DOWN);
	ft_mtrotate(&node, DOWN);
	ft_mtreverse_rotate(&node, DOWN);
	if (!found)
		return (0);
	ft_mtpush(&node, &found, RIGHT);
	ft_mtclear(&node);
	return (1);
}

int	main(void)
{
	t_mt	*ht;

	ht = NULL;
	if (!test(&ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ft_mtclear(&ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
