#include "mt.h"

// Helper para imprimir indentación con estilo 'tree'
void	print_tree_prefix(int depth, int is_last, int *branch_flags)
{
	for (int i = 0; i < depth; i++)
		ft_printf("%s", branch_flags[i] ? "|   " : "    ");
	if (depth > 0)
		ft_printf("%s── ", is_last ? "└" : "├");
}

// Imprime una lista interna con estilo 'tree'
void	print_inner_list(t_mt *inner_list, int depth, int *branch_flags)
{
	int	is_last;

	while (inner_list)
	{
		is_last = (inner_list->next == NULL);
		// Imprime el prefijo del árbol
		print_tree_prefix(depth, is_last, branch_flags);
		// Imprime el nodo actual
		ft_printf(BLUE "{%s}" RESET, inner_list->key);
		if (inner_list->type == BRANCH)
		{
			ft_printf("\n");
			branch_flags[depth] = !is_last;
			// Llamada recursiva para procesar hijos
			print_inner_list((t_mt *)inner_list->data, depth + 1, branch_flags);
		}
		else if (inner_list->type == LEAF)
			ft_printf(CYAN " \"%s\"" RESET, (char *)inner_list->data);
		ft_printf("\n");
		inner_list = inner_list->next;
	}
}

// Imprime un nodo con estilo 'tree'
void	print_node(t_mt *node, int depth, int *branch_flags)
{
	int	is_last;

	if (!node)
		return ;
	is_last = (node->next == NULL);
	// Imprime el prefijo del árbol
	print_tree_prefix(depth, is_last, branch_flags);
	// Imprime la clave del nodo
	ft_printf(YELLOW "[%s]" RESET, node->key);
	// Si el nodo es una rama, imprime sus hijos recursivamente
	if (node->type == BRANCH)
	{
		ft_printf("\n");
		branch_flags[depth] = !is_last; // Actualiza bandera de continuación
		print_inner_list((t_mt *)node->data, depth + 1, branch_flags);
	}
	else if (node->type == LEAF)
		ft_printf(CYAN " \"%s\"" RESET, (char *)node->data);
    if (is_last)
	    ft_printf("\n");
}

// Imprime los nodos del bucket como un árbol
void	print_bucket(t_mt *bucket, int depth, int *branch_flags)
{
	int	is_last;

	while (bucket)
	{
		is_last = (bucket->next == NULL);
		// Imprime nodo del bucket
		print_node(bucket, depth, branch_flags);
		// Actualiza las banderas para este nivel
		branch_flags[depth] = !is_last;
		bucket = bucket->next;
	}
}

// Imprime la tabla hash con estilo 'tree'
void	ft_mtprint_hash_table(t_hash_table *ht)
{
	size_t	i;

	int branch_flags[128] = {0}; // Rastrea qué niveles necesitan tuberías
	if (!ht)
		return ;
	i = 0;
	while (i < ht->bucket_count)
	{
		// Imprime el bucket como raíz
		ft_printf(GREEN "Bucket %d\n" RESET, i);
		if (!ht->buckets[i])
			ft_printf("    NULL\n");
		else
		{
			// Resetear banderas para cada bucket
			for (int j = 0; j < 128; j++)
				branch_flags[j] = 0;
			print_bucket(ht->buckets[i], 1, branch_flags);
		}
		ft_printf("\n"); // Separación clara entre buckets
		i++;
	}
}
