/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/06/05 12:00:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <stdlib.h>
# include <stdbool.h>

# include "libft.h"
# include "mtstructs.h"
# include "math.h"

#define PI		M_PI
#define TWO_PI	(2 * PI)
#define TAU     (2 * PI)   // vuelta completa

// Direcciones horizontales (en fracciones de vuelta sobre el plano XZ)
// 0.00 = 0° (NORTE = +Z), 0.25 = 90° (ESTE = +X), 0.50 = 180° (SUR = -Z), 0.75 = 270° (OESTE = -X)
#define NORTH   0.00f  // +Z (al frente)
#define EAST    0.25f  // +X (derecha)
#define SOUTH   0.50f  // -Z (atrás)
#define WEST    0.75f  // -X (izquierda)

// Elevación (ángulo vertical en fracción de vuelta)
// 0.00 = -90° (abajo), 0.50 = 0° (plano horizontal), 1.00 = +90° (arriba)
#define DOWN    0.00f  // -Y (bajar)
#define FLAT    0.5f  // horizontal (sin cambio en Y)
#define UP      1.00f  // +Y (subir)

#define DEGREE_NORTH 0.00f
#define DEGREE_EAST 90.00f
#define DEGREE_SOUTH 180.00f
#define DEGREE_WEST 270.00f

#define DEGREE_DOWN -90.00f
#define DEGREE_FLAT 0.00f
#define DEGREE_UP 90.00f


// ==================== Memory Management ====================

void			ft_mtfree(void *mt);
int             ft_mtremove(t_mt **head, t_mt *target, bool free_node);
void			ft_mtdelete(const char *key);
void			ft_mtclear(t_mt **lst);
t_mt			*ft_mtnew(const char *key);

// ==================== Count Functions ====================


// ==================== Iteration and Set Functions ====================


// ==================== Movement Functions ====================


// ==================== Deletion Functions ====================


// ==================== Insertion Functions ====================


// ==================== Add Functions ====================

int				ft_mtadd_back(t_mt **node, t_mt *new_node);

// ==================== Backup Functions =======================


// 
t_backup		*ft_backup_static(size_t slot_count, bool new, bool clear);
void			ft_backup_add(t_backup **backup, t_mt *node);
int 			ft_backup_clear(t_backup **backup);
void			ft_backup_remove(t_backup **backup, t_mt *node, bool free_target);

t_backup		*ft_backup_new(size_t slot_count);
void			ft_backup_add_slot(t_backup *backup, t_mt *node);
size_t			ft_hash(t_mt *key);
size_t          ft_hash_str(const char *str);
t_mt			*ft_backup_get(t_backup *backup, const char *key);

// ==================== Backup Slot Functions ====================
void			ft_backup_remove_slot(t_backup **backup, t_mt *slot, bool free_slot);
void            ft_backup_slot_update(t_backup **backup, size_t new_slot_count);
t_mt            **ft_backup_new_slots(size_t slot_count);


// ==================== Track Functions ====================
void			ft_backup_clear_tracks(t_track **tracks);
void			ft_backup_remove_track(t_track **tracker, t_track *node, bool free_target, bool free_node);
void			ft_backup_add_track(t_backup **backup, t_track *track);
void			ft_backup_free_track(t_track *track, bool free_node);
t_track			*ft_backup_new_track(const char *key, t_mt *node);
t_track         *ft_backup_get_track(t_track *track, const char *key);



// ==================== Filter Functions ====================


// ==================== Fold Functions ====================

// ==================== Collection Functions ====================

// ==================== Compare Functions ====================

int					ft_mtkeycmp(const t_mt *mt1, const char *key);

// ==================== Search Functions ====================


t_mt				*ft_mtfind(t_mt **head, t_mt *mt);

// ==================== Navigation Functions ====================
t_mt				*ft_mtlast(t_mt **node, bool move);


// ==================== Manipulation Functions ====================

// ===================== Getter Functions ====================
t_mt				*ft_mtget(const char *key);

char			    *ft_mtget_key(t_mt *mt);
int					ft_mtget_id(t_mt *mt);
void			    *ft_mtget_data(t_mt *mt);
void			    *ft_mtget_data_free(t_mt *mt);
void			    *ft_mtget_addon(t_mt *mt);
void			    *ft_mtget_addon_free(t_mt *mt);


// ==================== Setter Functions ====================

int                 ft_mtset(const char *key, void *data, void (*set_func)(struct s_mt *, void *));

void			    ft_mtset_key(t_mt *mt, const char *key);
void				ft_mtset_id(t_mt *mt, int id);
void				ft_mtset_data(t_mt *mt, void *data);
void				ft_mtset_data_free(t_mt *mt, void *data_free);

void				ft_mtset_addon(t_mt *mt, void *addon);
void				ft_mtset_addon_free(t_mt *mt, void *addon_free);


int					setter(int (*s_function)(t_args *args), void **s_ref,
                     const char *str, ...);
int					set_data(t_args *args);
int					set_mt(t_args *args);

// ==================== Constructor Functions ====================
void				*constructor(void *(*c_function)(t_args *args), const char *str, ...);
void            	*c_data(t_args *args);
void            	*c_mt(t_args *args);

// ==================== utils ====================

void set_mem(void **ptr, void *ptr2);

#endif // MT_H