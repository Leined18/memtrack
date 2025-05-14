/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:22:38 by danpalac          #+#    #+#             */
/*   Updated: 2025/05/14 19:03:52 by danpalac         ###   ########.fr       */
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




// ==================== Memory Management ====================

void			ft_data_def_free(t_data *data);
void			ft_mtdelete(void *mt);
void			ft_mtclear(t_mt **lst);
t_mt			*ft_mtnew(const char *key, t_data data, void (*free_func)(t_data *), t_backup **backup);
t_data			ft_data_new(void *item, size_t size, char *label, bool alloc);
t_mt 			*ft_mtnew2(const char *key, void *item, t_backup **backup);

// ==================== Count Functions ====================


// ==================== Offset Functions ====================
t_offset		ft_offset_sub(t_offset a, t_offset b);
t_offset		ft_offset_add(t_offset a, t_offset b);
t_offset		ft_offset_mul(t_offset a, t_offset b);
t_offset		ft_offset_inverse(t_offset o);
t_offset		ft_offset_new_degrees(float d_direction, float d_elevation, float distance);

// ==================== Offset Utils Functions ====================
float			ft_offset_direction(t_offset offset);
float			ft_offset_elevation(t_offset offset);
float			ft_dir_to_degrees(float direction);
float			ft_elev_to_degrees(float elevation);
float			ft_degrees_to_dir(float degrees);
float			ft_degrees_to_elev(float degrees);

t_offset		ft_offset_new(float direction, float elevation, float distance);
// ==================== Cords Functions ====================
t_cords		ft_cords_new(float x, float y, float z);
t_cords		ft_cords_add(t_cords a, t_cords b);
t_cords		ft_cords_sub(t_cords a, t_cords b);
float		ft_cords_distance(t_cords a, t_cords b);
t_cords		ft_calc_cords_2d(t_cords origin, t_offset offset);
t_cords		ft_calc_cords_3d(t_cords origin, t_offset offset);


// ==================== Iteration and Set Functions ====================


// ==================== Movement Functions ====================


// ==================== Deletion Functions ====================


// ==================== Insertion Functions ====================


// ==================== Add Functions ====================

void			ft_mtaddlast(t_mt **origin, t_mt *new, t_offset offset);

// ==================== Connection Funtions ====================
void			ft_mtclear_link(t_link **links);
t_link			*ft_linknew(t_mt *node, t_offset offset);
void			ft_linkadd_last(t_link **origin, t_link *link);
void			ft_linkadd_first(t_link **origin, t_link *link);
t_link			*ft_link_offset(t_link **links, t_offset offset);

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
t_mt			*ft_mtlast(t_mt **node, float direction, float elevation, bool move);


// ==================== Manipulation Functions ====================





#endif // MT_H