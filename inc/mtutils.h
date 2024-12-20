/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtutils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/20 10:27:05 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTUTILS_H
# define MTUTILS_H

# include "mtstructs.h"

/* Key manipulation utilities */
char	*ft_mtnew_key(char *prefix, char *suffix);
void	ft_mtadd_key_suffix(char *suffix, t_mt *node);
void	ft_mtadd_key_prefix(char *prefix, t_mt *node);

/* Data replacement utilities */
void	ft_replace_data(t_mt *current, void *new_data, t_data_type type);
void	ft_replace_key(t_mt *current, char *new_key);
void (*ft_mtget_free_data(t_data_type type))(void **);
void	ft_mtdel_by_type(void **data, t_data_type type);

/* Comparison utilities */
int		ft_mtcmp_key(t_mt *node, const char *key, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		cmp_int(void *a, void *b, size_t n);

/* Connect Utilties */
t_mt	*ft_mtconnect_left(t_mt *node, t_mt *left);
t_mt	*ft_mtconnect_right(t_mt *node, t_mt *right);
t_mt	*ft_mtconnect_up(t_mt *node, t_mt *up);
t_mt	*ft_mtconnect_down(t_mt *node, t_mt *down);

/* Disconnect Utilities */
t_mt	*ft_mtdisconnect_left(t_mt *node);
t_mt	*ft_mtdisconnect_right(t_mt *node);
t_mt	*ft_mtdisconnect_up(t_mt *node);
t_mt	*ft_mtdisconnect_down(t_mt *node);

t_mt	*ft_mtdisconnect_horizontal(t_mt *node);
t_mt	*ft_mtdisconnect_vertical(t_mt *node);

/* Printing utilities */
void	print_title(const char *title);
void	print_hashes_tables(t_hash_table *ht);
void	print_data(t_mt *node);

#endif // MTUTILS_H
