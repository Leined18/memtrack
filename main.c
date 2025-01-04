/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/04 22:40:53 by danpalac         ###   ########.fr       */
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
	int		c;
	t_mt	*node;

	node = *node1;
	node = ft_mtnew("key1", "value1", NONE);
	if (!node)
		return (0);
	ft_mtadd(&node, ft_mtnew("key2", "value2", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key3", "value3", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key4", "value4", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key5", "value5", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key6", "value6", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key7", "value7", NONE), DOWN);
	ft_mtadd(&node, ft_mtnew("key8", "value8", NONE), DOWN);
	ft_mtadd_aux(node, ft_mtnew("key9", "value9", NONE));
	ft_mtadd_aux(node, ft_mtnew("key10", "value10", NONE));
	ft_mtremove(&node, node);
	printf("size x: %ld\n", ft_abs(ft_mtsize_dimension(node, 'y', '-')));
	found = ft_mtsearch_cords(node, ft_mtcords(-1, 0, 0));
	if (!found)
		return (0);
	c = ft_cordscmp(ft_mtcords(4, 0, 0), found->cords);
	printf("Cords cmp: %d\n", c);
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
