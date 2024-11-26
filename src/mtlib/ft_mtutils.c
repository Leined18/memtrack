/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:43:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/26 11:50:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_replace(t_mt *current, void *new_data, t_data_type type)
{
	if (!current || !new_data)
		return ;
	if (current->type == LEAF)
		ft_mtdel_data(&current->data);
	else if (current->type == BRANCH)
		ft_mtdel_list(&current->data);
	current->data = new_data;
	if (current->type != type)
		current->type = type;
	if (current->type == BRANCH)
		current->free_data = ft_mtdel_list;
	else if (current->type == LEAF)
		current->free_data = ft_mtdel_data;
}

int	ft_mtcmp_key(t_mt *node, const char *key)
{
	if (!node || !key)
		return (0);
	return (ft_strcmp(node->key, key) == 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// Funciones auxiliares para mostrar gráficos
void	print_title(const char *title)
{
	printf("\n%s\n", "==========================");
	printf("   %s\n", title);
	printf("%s\n\n", "==========================");
}
int	cmp_int(void *a, void *b, size_t n)
{
	(void)n; // Evitar advertencias por parámetro no utilizado
	return (*(int *)a - *(int *)b);
}
