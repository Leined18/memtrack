/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtutils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/01 13:21:00 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTUTILS_H
# define MTUTILS_H

# include "mtstructs.h"

// ==================== Key manipulation utilities ====================

char	*ft_mtnew_key(char *prefix, char *suffix);
void	ft_mtadd_key_suffix(char *suffix, t_mt *node);
void	ft_mtadd_key_prefix(char *prefix, t_mt *node);

// ==================== Data replacement utilities ====================

void	ft_replace_data(t_mt *current, void *new_data, t_data_type type);
void	ft_replace_key(t_mt *current, char *new_key);
void (*ft_mtget_free_data(t_data_type type))(void **);
void	ft_mtdel_by_type(void **data, t_data_type type);

// ==================== Comparison utilities ====================

int		ft_mtcmp_key(t_mt *node, const char *key, size_t n);
int		ft_mtcmp_data(t_mt *node, void *data, t_data_type type);
int		ft_mtcmp_node(t_mt *node1, t_mt *node2);

// ==================== Connection utilities ====================

void	ft_connect_nodes(t_mt *node1, int direction1, t_mt *node2,
			int direction2);
void	ft_mtupdate_ref(t_mt **ref, t_mt *node);
void	ft_disconnect_node(t_mt *node, int direction);
void	ft_reconnect_single(t_mt *node, t_mt *single_node, int direction,
			int opposite);

// ==================== Printing utilities ====================

void	print_title(const char *title);
void	print_hashes_tables(t_hash_table *ht);
void	print_data(t_mt *node);

// ==================== Navigation utilities ====================

t_cords	ft_cords_diff(t_cords cords, int x, int y, int z);
t_cords	ft_cords(int x, int y, int z);
void	update_cords(t_mt *node, t_cords cords);

#endif // MTUTILS_H
