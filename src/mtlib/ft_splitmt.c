/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:59:34 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/25 18:17:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Splits the string 's' using the character 'c' as separator.
static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static t_mt	*ft_splitmt_create_node(const char *s, size_t len)
{
	char	*data;

	data = ft_strndup(s, len);
	if (!data)
		return (NULL);
	return (ft_mtnew("2", data, STRING));
}

static size_t	ft_splitmt_extract_word(const char *s, char c)
{
	char	*next_c;

	next_c = ft_strchr(s, c);
	if (next_c)
		return (size_t)(next_c - s);
	return (ft_strlen(s));
}

t_mt	*ft_splitmt(const char *s, char c)
{
	t_mt	*list;
	t_mt	*new_node;
	size_t	word_len;

	list = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_splitmt_extract_word(s, c);
			new_node = ft_splitmt_create_node(s, word_len);
			if (!new_node)
				return (ft_mtdel_list((void **)&list), NULL);
			ft_mtadd_back(&list, new_node);
			s += word_len;
		}
	}
	return (list);
}
