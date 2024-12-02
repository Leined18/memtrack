/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint_hash_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:30:24 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 12:30:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Helper para imprimir indentación con estilo 'tree'
void	print_tree_prefix(int depth, int is_last, int *branch_flags)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		if (branch_flags[i])
			ft_printf("|   ");
		else
			ft_printf("    ");
		i++;
	}
	if (depth > 0)
	{
		if (is_last)
			ft_printf("└── ");
		else
			ft_printf("├── ");
	}
}

// Imprime una lista interna con estilo 'tree'
void	print_inner_list(t_mt *inner_list, int depth, int *branch_flags)
{
	int	is_last;
	int	print;

	while (inner_list)
	{
		is_last = (inner_list->right == NULL);
		// Imprime el prefijo del árbol
		print_tree_prefix(depth, is_last, branch_flags);
		// Imprime el nodo actual
		print = 1;
		ft_printf(BLUE "{%s}" RESET, inner_list->key);
		if (inner_list->children)
		{
			ft_printf("\n");
			branch_flags[depth] = !is_last;
			print_inner_list(inner_list->children, depth + 1, branch_flags);
			print = 0;
		}
		ft_printf(CYAN " \"%s\"" RESET, (char *)inner_list->data);
		if (print)
			ft_printf("\n");
		inner_list = inner_list->right;
	}
}

// Imprime un nodo con estilo 'tree'
void	print_node(t_mt *node, int depth, int *branch_flags)
{
	int	is_last;

	if (!node)
		return ;
	is_last = (node->right == NULL);
	// Imprime el prefijo del árbol
	print_tree_prefix(depth, is_last, branch_flags);
	// Imprime la clave del nodo
	ft_printf(YELLOW "[%s]" RESET, node->key);
	// Si el nodo es una rama, imprime sus hijos recursivamente
	if (node->children)
	{
		ft_printf(BRIGHT_BLUE " \"%s\"\n" RESET, (char *)node->data);
		branch_flags[depth] = !is_last; // Actualiza bandera de continuación
		print_inner_list(node->children, depth + 1, branch_flags);
	}
    else
	    ft_printf(CYAN " \"%s\"\n" RESET, (char *)node->data);
	if (is_last)
		ft_printf("\n");
}

// Imprime los nodos del bucket como un árbol
void	print_bucket(t_mt *bucket, int depth, int *branch_flags)
{
	int	is_last;

	while (bucket)
	{
		is_last = (bucket->right == NULL);
		print_node(bucket, depth, branch_flags);
		branch_flags[depth] = !is_last;
		bucket = bucket->right;
	}
}

// Imprime la tabla hash con estilo 'tree'
void	ft_mtprint_hash_table(t_hash_table *ht)
{
	size_t	i;
	int		j;
	int		branch_flags[128];

	if (!ht)
		return ;
	i = -1;
	j = -1;
	ft_printf(BRIGHT_BLUE "Hash Table: " BRIGHT_GREEN "%s\n\n" RESET, ht->name);
	while (++i < ht->bucket_count)
	{
		ft_printf(GREEN "Bucket %d\n" RESET, i);
		if (!ht->buckets[i])
			ft_printf("    NULL\n");
		else
		{
			while (++j < 128)
				branch_flags[j] = 0;
			print_bucket(ht->buckets[i], 1, branch_flags);
		}
		ft_printf("\n");
	}
	print_hashes_tables(ht);
}
