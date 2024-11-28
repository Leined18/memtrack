/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtstructs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:39:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/28 09:54:27 by danpalac         ###   ########.fr       */
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
	LEAF,
	BRANCH,
	HASH_TABLE
}							t_data_type;

#endif // MTSTRUCTS_H
