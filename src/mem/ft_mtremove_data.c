/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtremove_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:03:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	ft_mtremove_data(t_mt *lst, char *key)
{
	t_mt	*current;

	current = lst;
	while (current)
	{
		if (ft_mtcmp_key(current, key, ft_strlen(key)))
		{
			ft_mtdel_by_type(&current->data, current->values.data_type);
			current->data = NULL;
		}
		if (current->children)
			ft_mtremove_data(current->children, key);
		current = current->right;
	}
}

// stacka = "miau" -> "guau" -> "mu" -> "le" -> "asd" -> "ñe" -> "sa"
// ft_mtremove(&stacka, "le", ft_strncmp, 2);
// stacka = "miau" -> "guau" -> "mu" -> (NULL) -> "asd" -> "ñe" -> "sa"
