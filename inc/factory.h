/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:34:03 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 18:36:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_H
# define FACTORY_H

# include "box.h"
# include "builder.h"
# include "libft.h"
# include "orders.h"

typedef int				(*t_factory_action)(struct s_factory **factory,
					struct s_builder **builder, void *arg, const char *id);

typedef struct s_factory
{
	const char			*id;
	t_builder			*builder;
	struct factory		*next;
	t_factory_action	actions[ORDER_COUNT];
}						t_factory;

t_factory				*create_factory(int id, t_builder *builder);
int						destroy_factory(t_factory **factory,
							t_builder **builder, void *arg, const char *id);
int						add_builder_factory(t_factory **factory,
							t_builder **builder, void *arg, const char *id);
int						destroy_all_factories(t_factory **factory,
							t_builder **builder, void *arg, const char *id);
int						get_box_factory(t_factory **factory, t_box **box,
							void *arg, const char *id);
int 					set_builder_factory(t_factory **factory,
							t_builder **builder, void *arg, const char *id);

#endif

// factory_H