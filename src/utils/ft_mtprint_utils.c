/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:27:19 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/02 11:48:43 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	print_title(const char *title)
{
	printf("\n%s\n", "==========================");
	printf("   %s\n", title);
	printf("%s\n\n", "==========================");
}

void	print_hashes_tables(t_hash_table *ht)
{
	t_mt	*list;
	t_mt	*current;

	if (!ht)
		return ;
	list = ft_mthash_collect_data_types(ht, HASH_TABLE);
	if (!list)
		return ;
	current = list;
	while (list)
	{
		ft_printf(PURPLE "%s" RESET BLUE "%s\n" RESET, "SUBTABLE is FROM: ",
			ht->name);
		ft_mtprint_hash_table((t_hash_table *)list->data);
		list = list->right;
	}
	ft_mtclear(&current);
}
