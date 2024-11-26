/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 11:17:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test_hash_table_operations(t_hash_table *ht)
{
	t_mt	*arr;
	t_mt	*result;

	ht = ft_mtnew_hash_table(3);
	if (!ht)
		return (0);
	// Insertamos datos en la tabla hash
	arr = ft_splitmt("HOME/DANPALAC/BIN:USR/BIN:KERNEL/BIN", ':');
	ft_mthash_insert(ht, "PATH", arr, BRANCH);
	ft_mthash_insert(ht, "NUMBERS", ft_mtnew("DECIMAL", ft_strdup("1234567890"),
			LEAF), BRANCH);
	ft_mthash_insert(ht, "LETTERS", ft_mtnew("LATIN", ft_strdup("ABCDEFGHIJ"),
			LEAF), BRANCH);
	ft_mthash_insert(ht, "HOLA", ft_strdup("hola"), LEAF);
	// Comprobamos si "PATH" se ha insertado correctamente
	result = ft_mthash_find_node(ht, "PATH");
	if (!result || ft_strcmp(result->key, "PATH") != 0)
		return (0);
	// Comprobamos la eliminación de "NUMBERS"
	ft_mthash_remove(ht, "LETTERS");
	result = ft_mthash_find_node(ht, "LETTERS");
	if (result)
		return (0); // No debe encontrar "NUMBERS" después de eliminarlo
	// Comprobamos la actualización de "HOLA"
	ft_mthash_insert(ht, "HOLA", ft_strdup("adios"), LEAF);
	result = ft_mthash_find_node(ht, "DECIMAL");
	if (!result || ft_strcmp((char *)result->data, "1234567890") != 0)
		return (0);
	ft_mtprint_hash_table(ht);
	ft_mtfree_hash_table(ht); // Liberamos la tabla hash
	return (1);               // Prueba exitosa
}


int	test(t_hash_table *ht)
{
	ht = ft_mtnew_hash_table(3);
	ht->put(ht, "key1", ft_strdup("value1"), LEAF);
	ht->put(ht, "key2", ft_strdup("value2"), LEAF);
	ht->put(ht, "key3", ft_strdup("value3"), LEAF);
    ht->put(ht, "key4", NULL, BRANCH);
	if (ft_strcmp((char *)ht->get_data(ht, "key1"), "value1") != 0)
		return (0);
    ft_mtadd_child(ht->get(ht, "key4"), ft_mtnew("key5", ft_strdup("value5"), LEAF));
    ft_mtadd_child(ht->get(ht, "key4"), ft_mtnew("key6", ft_strdup("value6"), LEAF));
    ht->put(ht, "key2", ft_mtnew("key0", ft_strdup("child"), LEAF), BRANCH);
    ht->put(ht, "key2", ft_mtnew("key1", ft_strdup("child1"), LEAF), BRANCH);
    ht->add_child(ht, "key2", ft_mtnew("key2", ft_strdup("child2"), LEAF));
	ht->print(ht);
	ht->free_hash(ht);
	return (1);
}

int	main(void)
{
	t_hash_table	*ht;

	ht = NULL;
	/*if (!test_hash_table_operations(ht))
	{
		ft_printf("Test hash table operations failed\n");
		if (ht)
			ft_mtfree_hash_table(ht);
		return (1);
	}*/
	if (!test(ht))
	{
		ft_printf("Test failed\n");
		if (ht)
			ft_mtfree_hash_table(ht);
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
