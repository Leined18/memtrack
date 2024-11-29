/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 14:42:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_mtnew_key(char *prefix, char *suffix);
void	ft_mtadd_key_suffix(char *suffix, t_mt *node);
void	ft_mtadd_key_prefix(char *prefix, t_mt *node);
void	ft_replace(t_mt *current, void *new_data, t_data_type type);

// cmp utils
int		ft_mtcmp_key(t_mt *node, const char *key);
int		ft_strcmp(const char *s1, const char *s2);
int		cmp_int(void *a, void *b, size_t n);

// print utils
void	print_title(const char *title);
void	print_hashes_tables(t_hash_table *ht);
;

#endif // UTILS_H