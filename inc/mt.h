/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 12:08:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"
# include "mtstructs.h"

typedef struct s_mt
{
	char				*key;
	t_data				data;
	struct s_mt			*aux;
	struct s_link		*links;
	struct s_list		*backup;
	struct s_cords		cords;
}				t_mt;


// ==================== Memory Management ====================

void			ft_mtdelete(void *mt);
void			ft_mtclear(t_mt **lst);
t_mt			*ft_mtnew(const char *key, t_data data, void (*free_ft)(t_data *), t_list **backup);
t_data			ft_data_new(void *data, size_t size, char *label, bool alloc);

// ==================== Count Functions ====================


// ==================== Iteration and Set Functions ====================


// ==================== Movement Functions ====================


// ==================== Deletion Functions ====================


// ==================== Insertion Functions ====================


// ==================== Add Functions ====================

void			ft_mtaddlast(t_mt **origin, t_mt *new, float direction, float distance);

// ==================== Connection Funtions ====================
void			ft_mtclear_link(t_link **links);
t_link			*ft_linknew(t_mt *node, float direction, float distance);
void			ft_linkadd_last(t_link **origin, t_link *link);
t_link			*ft_linkdirection(t_link **links, float direction);

// ==================== Backup Functions =======================
void			ft_mtbackup(t_list **backup, t_mt *node);


// ==================== Check Functions ====================


// ==================== Key Management ====================


// ==================== Filter Functions ====================


// ==================== Fold Functions ====================

// ==================== Collection Functions ====================


// ==================== Search Functions ====================


// ==================== Navigation Functions ====================
t_mt			*ft_mtlast(t_mt **node, float direction, bool move);


// ==================== Manipulation Functions ====================





#endif // MT_H