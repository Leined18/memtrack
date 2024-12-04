/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/04 11:28:03 by danpalac         ###   ########.fr       */
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
	LEAF,
	BRANCH
}							t_node_type;

typedef struct s_values
{
	t_data_type				data_type;
	t_node_type				node_type;
	size_t					size;
	int						count;
	int						to_free;
}							t_values;

#endif // MTSTRUCTS_H
