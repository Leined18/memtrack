/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtutils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/09 11:02:10 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTUTILS_H
# define MTUTILS_H

# include "mtstructs.h"

char	*ft_mtnew_key(char *prefix, char *suffix);
void	ft_mtadd_key_suffix(char *suffix, t_mt *node);
void	ft_mtadd_key_prefix(char *prefix, t_mt *node);
void	ft_replace(t_mt *current, void *new_data, t_data_type type);
void (*ft_mtget_free_data(t_data_type type))(void **);
void	ft_mtdel_by_type(void **data, t_data_type type);

// cmp utils
int		ft_mtcmp_key(t_mt *node, const char *key, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		cmp_int(void *a, void *b, size_t n);

// print utils
void	print_title(const char *title);
void	print_hashes_tables(t_hash_table *ht);
void	print_data(t_mt *node);

#endif // MTUTILS_H