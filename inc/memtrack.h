#ifndef NODE_H
# define NODE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mt
{
	void		**data;
	size_t		size;
	struct s_mt	*next;
}				t_mt;

t_mt			*ft_mtnew(void **data);
void			ft_mtadd_back(t_mt **lst, t_mt *new);

void			ft_mtremove(t_mt **lst, t_mt *remove);
t_mt			*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)());
t_mt			*ft_mtfind_data(t_mt *lst, void *data);
void			ft_mtiter(t_mt *lst, void (*f)(void *));
t_mt			*ft_mtlast(t_mt *lst);
void			ft_mtprint(t_mt *lst);
void			ft_mtadd_front(t_mt **lst, t_mt *new);
int				ft_mtsize(t_mt *lst);

void			ft_mtpop(t_mt **lst, t_mt *remove);
void			ft_mtclear(t_mt **lst, void (*del_func)());
void			ft_mtdel_data(void **data, size_t size);

#endif // LIST_H