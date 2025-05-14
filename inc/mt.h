/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 15:04:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"
# include "mtstructs.h"




// ==================== Memory Management ====================

void			ft_data_def_free(t_data *data);
void			ft_mtdelete(void *mt);
void			ft_mtclear(t_mt **lst);
t_mt			*ft_mtnew(const char *key, t_data data, void (*free_func)(t_data *), t_backup **backup);
t_data			ft_data_new(void *item, size_t size, char *label, bool alloc);

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
t_slot			*ft_slotnew(size_t slot_count);
void			ft_backup_add(t_backup **backup, t_mt *node);
void			ft_backup_free(t_backup **backup);
t_backup		*ft_backup_new(size_t slot_count);



// ==================== Filter Functions ====================


// ==================== Fold Functions ====================

// ==================== Collection Functions ====================


// ==================== Search Functions ====================

t_mt			*ft_mtsearch(t_mt *start, t_data data, bool (*filter)(t_mt *, t_data));


// ==================== Navigation Functions ====================
t_mt			*ft_mtlast(t_mt **node, float direction, bool move);


// ==================== Manipulation Functions ====================





#endif // MT_H