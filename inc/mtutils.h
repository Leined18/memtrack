/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtutils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/04/30 16:11:01 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTUTILS_H
# define MTUTILS_H

# include "mtstructs.h"

// ==================== Key manipulation utilities ====================

char			*ft_mtnew_key(char *prefix, char *suffix);
void			ft_mtadd_key_suffix(char *suffix, t_mt *node);
void			ft_mtadd_key_prefix(char *prefix, t_mt *node);

// ==================== Data replacement utilities ====================

void			ft_replace_data(t_mt *current, void *new_data,
					t_data_type type);
void			ft_replace_key(t_mt *current, char *new_key);
t_free_funtion	ft_mtget_free_data(t_data_type type);
void			ft_mtdel_by_type(void **data, t_data_type type);

// ==================== Comparison utilities ====================

int				ft_mtcmp_key(t_mt *node, const char *key, size_t n);
int				ft_mtcmp_data(t_mt *node, void *data, t_data_type type);
int				ft_mtcmp_node(t_mt *node1, t_mt *node2);
int				ft_cordscmp(t_cords a, t_cords b);

// ==================== Connection utilities ====================

void			ft_mtconnect(t_mt *node, t_mt *node_to_connect,
					t_direction direction);
void			ft_mtdisconnect(t_mt *node, t_direction direction);
void			ft_mtupdate_ref(t_mt **ref, t_mt *node);
int				ft_mtoposite_direction(int direction);


#endif // MTUTILS_H
