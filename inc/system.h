/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:15 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 21:42:14 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "box.h"
# include "builder.h"
# include "factory.h"
# include "libft.h"
# include "orders.h"

typedef struct s_system
{
	t_box			*boxes;
	t_builder		*builders;
	t_factory		*factories;
	size_t			box_count;
	size_t			builder_count;
	size_t			factory_count;
	int				id;
	void			(*broadcast)(struct s_system *system, t_order order,
					void *data, const char *id);
}					t_system;
