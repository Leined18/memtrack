/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:31:20 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/24 23:33:57 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "libft.h"
# include "orders.h"

typedef int			(*t_box_action)(struct t_box **box, void *arg,
				const char *id);

typedef struct s_box
{
	char			*id;
	void			*data;
	size_t			size;
	t_box_action	actions[ORDER_COUNT];
	struct s_box	*next;
}					t_box;

t_box				*create_box(const char *id, void *data, size_t size);
int					destroy_box(t_box **box, void *arg, const char *id);
int					destroy_box_data(t_box **box, void *arg, const char *id);

#endif // BOX_H