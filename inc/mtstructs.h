/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/21 11:11:36 by danpalac         ###   ########.fr       */
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
	bool 					valid;
}							t_cords;

/**
 * t_data - Estructura de datos genérica.
 * @item: Puntero a los datos.
 * @size: Tamaño de los datos.
 * @label: Etiqueta del dato.
 * @alloc: Indica si el dato fue asignado dinámicamente.
 * @free: Función de liberación de memoria.
 * @type: Tipo de dato (0: int, 1: float, 2: double, 3: char, 4: string).
 * @id: ID del nodo.
 */

typedef struct s_data
{
	int 		id; // ID del nodo
	void		*item;
	bool 		alloc;
	size_t		size;
	int 		type; // Tipo de datos (0: int, 1: float, 2: double, 3: char, 4: string)
	char		*label; // Etiqueta del dato
	void		(*free)();
} t_data;

/**
 * t_offset - Estructura de offset.
 * @direction: Dirección horizontal (0.0 a 1.0).
 * @elevation: Elevación (0.0 a 1.0).
 * @distance: Distancia euclidiana.
 * @valid: Indica si el offset es válido.
 */

typedef struct s_offset
{
	float 		direction;      // Angulo horizontal (0.0 a 1.0)
	float 		elevation;      // Angulo vertical (0.0 a 1.0)
	float 		distance; 		// Distancia euclidiana
	bool 		valid;          // Indica si el offset es válido
} t_offset;

/**
 * t_link - Estructura de conexión entre nodos.
 * @key: Clave del nodo conectado.
 * @offset: Offset de la conexión.
 * @node: Nodo conectado.
 * @next: Siguiente conexión (lista enlazada).
 * @prev: Conexión anterior (lista enlazada).
 * @weight: Peso de la conexión.
 * @status: Estado de la conexión (true: activa, false: inactiva).
 */

typedef struct s_link
{
	char 			*key;
	struct s_offset	offset;
	struct s_mt		*node;
	struct s_link 	*next;
	struct s_link 	*prev;
	float			weight;
	bool			status;
}	t_link;

/**
 * t_track - Estructura de seguimiento de conexiones. lista para eliminar
 * @key: Clave del nodo conectado.
 * @node: Nodo conectado.
 * @next: Siguiente conexión (lista enlazada).
 * @timestamp: Marca de tiempo de la conexión.
 * @priority: Prioridad de la conexión.
 * @backup_id: ID del backup.
 */

typedef struct s_track
{
	char 				*key;           // Clave del nodo
	struct s_mt			*node;          // Nodo conectado
	struct s_track		*next;         // Siguiente conexión (lista enlazada)
	time_t 				timestamp;      // Marca de tiempo de la conexión
	int 				priority;       // Prioridad de la conexión
	int 				backup_id;      // ID del backup
} t_track;

/**
 * t_args - Estructura de argumentos para funciones de construcción y asignación.
 * @tokens: Array de cadenas de caracteres (tokens).
 * @count: Cantidad de tokens.
 * @ap: Lista de argumentos variables.
*/

typedef struct s_args
{
	char **tokens;
	int count;
	va_list ap;
	void **s_ref;
} t_args;


/**
 * t_backup - Estructura de backup.
 * @id: ID del backup.
 * @slots: Array de punteros a nodos.
 * @slot_count: Cantidad de slots.
 * @item_count: Cantidad de items.
 * @tracker: Lista de seguimiento de conexiones.
 * @backup_id: ID del backup.
 */

typedef struct s_backup
{
	int 				id;
	struct s_mt			**slots;
	size_t				slot_count;
	size_t				item_count;
	struct s_track		*tracker;
} t_backup;


/**
 * t_mt - Estructura Principal.
 * @id: Identificador único del nodo.
 * @key: Clave del nodo.
 * @data: Puntero genérico a los datos del nodo.
 * @aux: Nodo auxiliar.
 * @links: Puntero genérico para conexiones.
 * @backup: Estructura de backup.
 * @cords: Puntero a coordenadas del nodo (opcional).
 * @next: Siguiente nodo en la lista.
 */

typedef struct s_mt
{
    int					id;
    char				*key;
    void				*data;
	void				(*free)();
    struct s_mt			*aux;
    void				*links;
    struct s_backup		*backup;
    struct s_cords		*cords;
    struct s_mt 		*next;
	bool				status;
	int					type;
}				t_mt;






#endif
