/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:49:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include "libft.h"
# include "mt.h"

typedef struct s_cords
{
	float					x;
	float					y;
	float					z;
}							t_cords;

typedef struct s_data
{
	void		*item;
	size_t		size;
	char		*label;
	bool 		alloc;
	void		(*free)(struct s_data *);
} t_data;

typedef struct s_offset
{
	float 		direction;      // Angulo horizontal (0.0 a 1.0)
	float 		elevation;      // Angulo vertical (0.0 a 1.0)
	float 		distance; 		// Distancia euclidiana
} t_offset;

typedef struct s_link
{
	struct s_offset	offset;       // Offset de la conexión
	struct s_mt		*node;          // Nodo conectado
	struct s_link 	*next;        // Siguiente conexión (lista enlazada)
	struct s_link 	*prev;        // Conexión anterior (lista enlazada)
}	t_link;

typedef struct s_slot
{
	struct t_mt   *node;
	struct s_slot *next;
} t_slot;

typedef struct s_backup
{
	t_slot		*slots;
	size_t		slot_count;
	size_t		item_count;
	t_list		*tracker;
} t_backup;


/**
 * t_mt - Estructura Principal.
 * @key: Clave del nodo.
 * @data: Datos del nodo.
 * @aux: Nodo auxiliar.
 * @links: Lista de conexiones.
 * @backup: Estructura de backup.
 * @cords: Coordenadas del nodo.
 */

typedef struct s_mt
{
	char				*key;
	struct s_data		data;
	struct s_mt			*aux;
	struct s_link		*links;
	struct s_backup		*backup;
	struct s_cords		cords;
}				t_mt;






#endif
