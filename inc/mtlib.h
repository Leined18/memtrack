
#ifndef MTLIB_H
# define MTLIB_H

# include "libft.h"
# include "mtstructs.h"

// Function declarations and other definitions for the mtlib library

void	freedom(void **data);
t_mt	*ft_splitmt(const char *s, char c);

#endif // MTLIB_H