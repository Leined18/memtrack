/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/14 15:08:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtrack.h"

void	ft_mtdelete(t_mt **list, int (*match)(t_mt *))
{
	t_mt	*current;
	t_mt	*prev;

	current = *list;
	prev = NULL;
	while (current)
	{
		if (match(current))
		{
			if (prev)
				prev->next = current->next;
			else
				*list = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

t_mt	*ft_mtsearch(t_mt *list, int (*match)(t_mt *))
// Busca el primer nodo que cumpla la condición
{
	while (list)
	{
		if (match(list))
			return (list);
		list = list->next;
	}
	return (NULL);
}

int	ft_mt_infinite_loop_detection(t_mt *list)
{
	t_mt	*slow;
	t_mt	*fast;

	slow = list;
	fast = list;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1); // Ciclo detectado
	}
	return (0); // No hay ciclo
}

int	main(void)
{
	t_mt	*str;
	t_mt	*str2;

	ft_mtpush_data(&str, ft_strdup("Pío"));
	ft_mtpush_data(&str, ft_strdup("Muu"));
	ft_mtpush_data(&str, ft_strdup("Miau"));
	ft_mtpush_data(&str, ft_strdup("Guau"));
	ft_mtpush_data(&str2, ft_strdup("Cocorocó"));
	ft_mtpush_data(&str2, ft_strdup("Ñee"));
	ft_mtpush_data(&str2, ft_strdup("GUAGAU"));
	ft_mtpush_data(&str2, ft_strdup("ElpsyKongroo"));
	ft_mtpush_data(&str2, ft_strdup("Cuack"));
	ft_mtinsert_index(&str2, ft_mtnew(ft_strdup("AUREKSADIA")), 0);
	ft_mtmigrate(&str, &str2);
	ft_printf("str: ");
	ft_mtprint(str, 1, " ");
	ft_printf("str2: ");
	ft_mtprint(str2, 1, " ");
	(void)str;
	(void)str2;
	return (0);
}
