/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:12:30 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 07:16:22 by danpalac         ###   ########.fr       */
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

int	ft_addresscmp(void *data, void *data2)
{
	if (data == data2)
		return (0);
	return (1);
}

int	main(void)
{
	t_mt	*stacka;
	t_mt	*stackb;

	ft_mtpush_data(&stacka, "1");
	ft_mtpush_data(&stackb, "2");
	ft_mtpush_data(&stacka, "3");
	ft_mtpush_data(&stackb, "4");
	ft_mtpush_data(&stacka, "5");
	ft_mtpush_data(&stackb, "6");
	ft_mtpush_data(&stacka, "7");
	ft_mtpush_data(&stackb, "8");
	ft_mtreplace(&stacka, &stackb);
	ft_mtprint(stacka, 1, " ");
	ft_printf("\n");
	ft_mtprint(stackb, 1, " ");
	ft_mterase(&stacka);
	ft_mtprint(stacka, 1, " ");
	ft_mtprint(chaosmatrix(0, 0, 1), 0, "\n");
	return (0);
}
