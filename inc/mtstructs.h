/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/09 21:20:45 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include "libft.h"
# include "mt.h"

typedef void (*t_free_func)(void *);

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
	char 				*group_id; // ID del grupo al que pertenece el track
	char 				*id;
	struct s_mt			*node;
	struct s_track		*next;
	struct s_track		*pointer;	
} t_track;

/**
 * t_group - Estructura de grupo de tracks.
 * @id: ID del grupo.
 * @tracks: Lista de tracks en el grupo.
 * @track_count: Cantidad de tracks en el grupo.
 * @next: Puntero al siguiente grupo.
 *
 * Esta estructura representa un grupo de tracks, donde cada track puede
 * pertenecer a un grupo específico. Los grupos permiten organizar los tracks
 * de manera jerárquica o categorizada.
 */

typedef struct s_group
{
	char *id;
	
	struct s_track *head; // Lista de tracks en el grupo
	size_t track_count; // Cantidad de tracks en el grupo
	struct s_group *next; // Puntero al siguiente grupo
} t_group;


typedef struct s_slot
{
	char *id; // ID del slot
	char *group_id; // ID del grupo al que pertenece el slot

	struct s_mt *node; // Nodo asociado al slot
	struct s_slot *top; // Puntero al nodo superior del slot
} t_slot;

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
	struct s_slot		**slots;
	size_t				slot_count;
	size_t				item_count;
	struct s_group		*groups; // Lista de grupos
} t_backup;

/**
 * t_mt - Estructura Principal.
 * @id: Identificador único del nodo.
 * @key: Clave del nodo.
 * @data: Puntero genérico a los datos del nodo.
 * @addon: Puntero genérico a datos adicionales del nodo.
 * @data_free: Función para liberar los datos del nodo.
 * @addon_free: Función para liberar los datos adicionales del nodo.
 * @next: Puntero al siguiente nodo en la lista.
 * @prev: Puntero al nodo anterior en la lista.
 * @pointer: Puntero a un nodo relacionado (opcional).
 * @backup: Puntero a la estructura de backup asociada al nodo.
 */

typedef struct s_mt
{
    char				*id;
    char				*group_id; // ID del grupo al que pertenece el nodo
    void				*data;
	void				*addon;
	t_free_func			data_free;
	t_free_func			addon_free;
	struct s_mt			*next;
	struct s_mt 		*prev;
	struct s_mt			*pointer;
    struct s_backup		*backup;
}				t_mt;






#endif
