/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 12:52:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test(t_hash_table **ht)
{
	t_mt	*node;
	t_mt	*found;

	(void)ht;
	node = NULL;
	node = ft_mtnew("key1", "value1", NONE);
	if (!node)
		return (0);
	ft_mtadd_right(&node, ft_mtnew("key2", "value2", NONE));
	ft_mtadd_left(&node, ft_mtnew("key3", "value3", NONE));
	ft_mtadd_right(&node, ft_mtnew("key4", "value4", NONE));
	ft_mtadd_up(&node, ft_mtnew("key5", "value5", NONE));
	ft_mtadd_down(&node, ft_mtnew("key6", "value6", NONE));
	ft_mtadd_down(&node, ft_mtnew("key7", "value7", NONE));
	found = ft_mtsearch_key(node, "key7");
	if (!found)
		return (0);
	ft_mtremove(&node, found);
	ft_mtclear(&node);
	return (1);
}

int	main(void)
{
	t_hash_table	*ht;

	ht = NULL;
	if (!test(&ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ht->methods.free_table(ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
