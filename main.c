/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 12:51:55 by danpalac         ###   ########.fr       */
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
	ht->put(ht, "ANIMALS", ft_splitmt("DOG:CAT:RABBIT", ':'), BRANCH);
	ht->put(ht, "COLORS", ft_splitmt("RED:GREEN:BLUE", ':'), BRANCH);
	ht->put(ht, "NUMBERS", ft_splitmt("ONE:TWO:THREE", ':'), BRANCH);
	ht->put(ht, "LETTERS", ft_splitmt("A:B:C", ':'), BRANCH);
	print_title("Test replace key");
    ht->replace_key(ht, "ANIMALS", "ANIMALES");
    ft_mtprint(ht->get_data(ht, "ANIMALES"), 1, "->");
	print_title("Test replace data");
	ft_mthash_replace_data(ht, "ANIMALES", ft_strdup("HUSKY"), LEAF);
	ft_mtprint(ht->get_data(ht, "PERRO"), 1, "->");
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
