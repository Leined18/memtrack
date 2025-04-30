/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtprint_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:27:19 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/30 15:43:25 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

void	print_title(const char *title)
{
	printf("\n%s\n", "==========================");
	printf("   %s\n", title);
	printf("%s\n\n", "==========================");
}

void	print_data(t_mt *node)
{
	if (node->values.data_type == STRING)
		ft_printf(CYAN " \"%s\"" RESET, (char *)node->data);
	else
		ft_printf(CYAN " %p" RESET, node->data);
}
