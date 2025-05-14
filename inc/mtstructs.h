/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 11:53:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cords
{
	float					x;
	float					y;
	float					z;
}							t_cords;

typedef struct s_data
{
	void		*data;
	size_t		size;
	char		*label;
	bool 		alloc;
	void		(*free)(struct s_data *);
} t_data;

typedef struct s_link
{
	float		direction;      // Dirección en float (0.0 a 1.0)
	float		distance;       // Distancia de separación
	struct s_mt	*node;          // Nodo conectado
	struct s_link *next;        // Siguiente conexión (lista enlazada)
	struct s_link *prev;        // Conexión anterior (lista enlazada) m
}	t_link;





#endif
