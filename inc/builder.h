/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:13:17 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_H
# define BUILDER_H

# include "box.h"
# include "libft.h"
# include "orders.h"

typedef int				(*t_builder_action)(struct s_builder **builder,
					t_box **box, void *arg, const char *id);

typedef struct s_builder
{
	const char			*id;
	t_box				*box;
	t_builder_action	actions[ORDER_COUNT];
	struct s_builder	*next;
}						t_builder;

t_builder				*create_builder(int id, t_box *box);
void					destroy_builder(t_builder **builder, t_box **box,
					void *arg, const char *id);
int						add_box_builder(t_builder **builder, t_box **box,
					void *arg, const char *id);
int						destroy_all_builders(t_builder **builder,
					t_box **box, void *arg, const char *id);
void					*get_box_builder(t_builder **builder, t_box **box,
							void *arg, int id);

#endif