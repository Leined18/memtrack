/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:59:34 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/20 12:15:25 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

// Splits the string 's' using the character 'c' as separator.
char	*ft_strndup(const char *s, size_t n)
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
t_mt	*ft_splitmt(char const *s, char c)
{
	t_mt	*list;
	t_mt	*new_node;
	size_t	word_len;

	if (!s)
		return (NULL);
	list = NULL;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			new_node = ft_mtnew_chaos(ft_strndup(s, word_len));
			if (!new_node)
				return (NULL);
			new_node->size = 1;
			(ft_mtadd_back(&list, new_node), s += word_len);
		}
	}
	return (list);
}
