#ifndef MEMTRACK_H
# define MEMTRACK_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_mt
{
	void		*data;
	size_t		size;
	int			count;
	int			n;
	struct s_mt	*next;
}				t_mt;

t_mt			*ft_mtnew(void *data);
void			ft_mtadd_back(t_mt **lst, t_mt *new);
void			ft_mtpush_data(t_mt **lst, void *data);
void			ft_mtpush_data_back(t_mt **lst, void *data);

void			ft_mtremove(t_mt **lst, t_mt *remove);
t_mt			*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)());
t_mt			*ft_mtfind_data(t_mt *lst, void *data);
void			ft_mtiter(t_mt *lst, void (*f)(void *));
t_mt			*ft_mtlast(t_mt *lst);
void			ft_mtprint(t_mt *lst, int b, char *c);
void			ft_mtprint_n(t_mt *lst, int b, char *c);
void			ft_mtadd_front(t_mt **lst, t_mt *new);
int				ft_mtsize(t_mt *lst);
void			ft_mtmigrate_back(t_mt **src, t_mt **dest);

void			ft_mtpop(t_mt **lst, t_mt *remove);
void			ft_mtclear(t_mt **lst, void (*del_func)());
void			ft_mtdel_data(t_mt **list);

// operations
void			ft_mtmigrate(t_mt **src, t_mt **dest);
void			ft_mtpush(t_mt **src, t_mt **dest);
void			ft_mtpush_back(t_mt **src, t_mt **dest);
void			ft_mtrotate(t_mt **list);
void			ft_mtreverse_rotate(t_mt **list);
void			ft_mtswap(t_mt **list);
void			ft_mtswap_nodes(t_mt *node1, t_mt *node2);
void			ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos);

// mtlib
void			*chaosmatrix(int count, size_t size, int flag);
void			freedom(void **data, t_mt **list);
char			*ft_strmtdup(const char *s1);
char			*ft_submtstr(char const *s, unsigned int start, size_t len);
char			**ft_splitmt(char const *s, char c);

#endif // LIST_H