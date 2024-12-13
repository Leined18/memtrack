/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:48:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/13 20:57:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

/**
 * ft_mtprint - Imprime un grafo de nodos de forma recursiva.
 * @mt: Nodo inicial del grafo.
 */

int	test(t_hash_table *ht)
{
	ht = ft_mthash_new_table(1, "test");
	if (!ht)
		return (0);
	ft_mtadd_back(&ht->buckets[0], ft_mtnew("key1", ft_strdup("value1"),
			STRING));
	ft_mtadd_back(&ht->buckets[0], ft_mtnew("key2", ft_strdup("value2"),
			STRING));
	ft_mthash_insert_child(ht, "key1", "key3", ft_strdup("value3"), STRING);
	ft_mthash_insert_child(ht, "key2", "key4", ft_strdup("value4"), STRING);
	ft_mthash_insert_child(ht, "key1", "key5", ft_strdup("value5"), STRING);
	ft_mthash_insert_child(ht, "key2", "key6", ft_strdup("value6"), STRING);
	ft_mthash_insert_child(ht, "key1", "key7", ft_strdup("value7"), STRING);
	ft_mthash_insert_child(ht, "key2", "key8", ft_strdup("value8"), STRING);
	ft_printf("\n\n");
	ht->methods.remove(ht, "key5");
	ht->methods.replace_node(ht, "key1", ft_mtnew("key9", ft_strdup("value9"),
			STRING));
	ht->methods.print(ht);
	ht->methods.free_table(ht);
	return (1);
}

#include "mem.h"

/**
 * ft_mtiter
	- Aplica una función a cada nodo de la lista y devuelve la suma total.
 * @lst: Lista a recorrer.
 * @func: Función personalizada a aplicar a cada nodo.
 *

	* La función devuelve la suma de los valores que retorna la función personalizada
 * al ser aplicada a cada nodo.
 */

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
