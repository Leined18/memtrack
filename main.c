/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 21:04:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * test_hash_table_operations - Prueba las operaciones de la tabla hash.
 *
 * Retorna 1 si la prueba fue exitosa, 0 si falló.
 */

int	test_hash_table_operations(void)
{
	t_hash_table	*ht;
	t_mt			*arr;
	t_mt			*result;

	ht = ft_mtnew_hash_table(3);
	if (!ht)
		return (0);
	// Insertamos datos en la tabla hash
	arr = ft_splitmt("HOME/DANPALAC/BIN:USR/BIN:KERNEL/BIN", ':');
	ft_mthash_insert(ht, "PATH", arr, LIST);
	ft_mthash_insert(ht, "NUMBERS", ft_mtnew("DECIMAL", ft_strdup("1234567890"),
			STRING), LIST);
	ft_mthash_insert(ht, "LETTERS", ft_mtnew("LATIN", ft_strdup("ABCDEFGHIJ"),
			STRING), LIST);
	ft_mthash_insert(ht, "HOLA", ft_strdup("hola"), STRING);
	// Comprobamos si "PATH" se ha insertado correctamente
	result = ft_mthash_find(ht, "PATH");
	if (!result || ft_strcmp(result->key, "PATH") != 0)
		return (0);
	// Comprobamos la eliminación de "NUMBERS"
	ft_mthash_remove(ht, "LETTERS");
	result = ft_mthash_find(ht, "LETTERS");
	if (result)
		return (0); // No debe encontrar "NUMBERS" después de eliminarlo
	// Comprobamos la actualización de "HOLA"
	ft_printf("index: %d\n", ft_mthash_find_index(ht, "DECIMAL"));
	ft_mthash_insert(ht, "HOLA", ft_strdup("adios"), STRING);
	result = ft_mthash_find(ht, "HOLA");
	if (!result || ft_strcmp((char *)result->data, "adios") != 0)
		return (0);
	ft_mtprint_hash_table(ht);
	ft_mtfree_hash_table(ht); // Liberamos la tabla hash
	return (1);               // Prueba exitosa
}

int	main(void)
{
	if (!test_hash_table_operations())
	{
		ft_printf("Test hash table operations failed\n");
		return (1);
	}
	ft_printf(GREEN "All tests passed successfully\n" RESET);
	return (0);
}
