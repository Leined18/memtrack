
#ifndef MTLIB_H
# define MTLIB_H

# include "libft.h"
# include "mt.h"
# include "mtstructs.h"

// Function declarations and other definitions for the mtlib library
// mtlib
void	*chaosmatrix(int count, size_t size, int flag);
void	freedom(void **data, t_mt **list);
char	*ft_strmtdup(const char *s1);
char	*ft_submtstr(char const *s, unsigned int start, size_t len);
t_mt	*ft_splitmt(const char *s, char c);

// utils
int		ft_mtcmp_key(t_mt *node, const char *key);
int		ft_strcmp(const char *s1, const char *s2);
void	print_title(const char *title);
int		cmp_int(void *a, void *b, size_t n);

#endif // MTLIB_H