/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_factory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:43:13 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:23:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factory.h"

int	destroy_factory(t_factory **factory, t_builder **builder, void *arg,
		const char *id)
{
	if (!factory || !*factory)
		return (0);
	if (builder && *builder)
	{
		(*builder)->destroy(*builder, NULL, arg, id);
		*builder = NULL;
	}
	if ((*factory)->builders)
}