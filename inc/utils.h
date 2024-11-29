/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:22:49 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/29 13:47:03 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_mtnew_key(char *prefix, char *suffix);
void	ft_mtadd_key_suffix(char *suffix, t_mt *node);
void	ft_mtadd_key_prefix(char *prefix, t_mt *node);

// utils
int		ft_mtcmp_key(t_mt *node, const char *key);
int		ft_strcmp(const char *s1, const char *s2);
int		cmp_int(void *a, void *b, size_t n);

void	print_title(const char *title);
void	ft_replace(t_mt *current, void *new_data, t_data_type type);

#endif // UTILS_H