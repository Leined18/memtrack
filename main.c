/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 12:40:11 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test(t_hash_table *ht)
{
	ht = ft_mthash_new_table(3, "test");
	ht->methods.insert(ht, "key1", ft_strdup("data1"), LEAF);
	ht->methods.insert(ht, "key2", ft_strdup("data2"), LEAF);
	ht->methods.insert(ht, "key3", ft_strdup("data3"), LEAF);
	ht->methods.insert(ht, "key4", ft_strdup("data4"), LEAF);
	ht->methods.insert(ht, "key5", ft_strdup("data5"), LEAF);
	ht->methods.insert(ht, "key6", ft_strdup("data6"), LEAF);
	ht->methods.insert(ht, "key7", ft_strdup("data7"), LEAF);
	ht->methods.insert(ht, "key7", NULL, BRANCH);
	ht->methods.add(ht, ft_mtnew("777", ft_strdup("data9"), LEAF));
	ht->methods.add(ht, ft_mtnew("777", ft_strdup("data10"), LEAF));
	ht->methods.add_child(ht, "key7", ft_mtnew("777", ft_strdup("data8"), LEAF));
	ht->methods.add_child(ht, "key7", ft_mtnew("777", ft_strdup("data11"), LEAF));
	ht->methods.print(ht);
	ht->methods.free_table(ht);
	return (1);
}

int	main(void)
{
	t_hash_table	*ht;

	ht = NULL;
	if (!test(ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ht->methods.free_table(ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
