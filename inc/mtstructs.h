/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/18 11:49:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include <stdio.h>
# include <stdlib.h>

// Ahora puedes usar estos tipos en las siguientes estructuras
typedef struct s_mt			t_mt;
typedef struct s_hash_table	t_hash_table;
// Definir el enum t_data_type completamente antes de usarlo

typedef struct s_cords
{
	int						x;
	int						y;
	int						z;
}							t_cords;

typedef struct s_vectors
{
	t_mt					*left;
	t_mt					*right;
	t_mt					*up;
	t_mt					*down;
}							t_vectors;

typedef enum e_data_type
{
	NONE,
	PTR,
	STRING,
	LIST,
	HASH_TABLE
}							t_data_type;

typedef enum e_node_type
{
	ROOT,
	LEAF,
	BRANCH
}							t_node_type;

typedef struct s_values
{
	int						data_type;
	int						node_type;
	size_t					size;
	int						count;
	int						to_free;
	int						state;
}							t_values;

#endif // MTSTRUCTS_H
