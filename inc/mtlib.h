
#ifndef MTLIB_H
# define MTLIB_H

# include "libft.h"
# include "mtstructs.h"

// Function declarations and other definitions for the mtlib library
// mtlib
void	*chaosmatrix(int count, size_t size, int flag);
void	freedom(void **data, t_mt **list);
char	*ft_strmtdup(const char *s1);
char	*ft_submtstr(char const *s, unsigned int start, size_t len);
t_mt	*ft_splitmt(const char *s, char c);

#endif // MTLIB_H