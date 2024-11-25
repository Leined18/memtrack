#ifndef LIST_H
# define LIST_H

# include "libft.h"
# include "mem.h"
# include "mtlib.h"
# include "mtstructs.h"

// memtrack functions
t_mt	**ft_mtfind_cmp_ref(t_mt **lst, void *data, int (*cmp)(), size_t n);
t_mt	*ft_mtfind_cmp(t_mt *lst, void *data, int (*cmp)(), size_t n);
t_mt	*ft_mtget_cmp(t_mt **lst, void *data, int (*cmp)(), size_t n);
t_mt	*ft_mtsearch_mt(t_mt *root, const char *key, int (*cmp)(t_mt *,
				const char *));

void	ft_mtadd_back(t_mt **lst, t_mt *new);
void	ft_mtiter(t_mt *lst, void (*f)(void *));
t_mt	*ft_mtlast(t_mt *lst);
void	ft_mtprint(t_mt *lst, int b, char *c);
void	ft_mtprint_n(t_mt *lst, int b, char *c);
void	ft_mtadd_front(t_mt **lst, t_mt *new);
int		ft_mtsize(t_mt *lst);
void	ft_mtmigrate_back(t_mt **src, t_mt **dest);
void	ft_mtpop_back(t_mt **lst);
void	ft_mtpop(t_mt **lst);
void	ft_mtpop_cmp(t_mt **lst, void *remove, int (*cmp)(), size_t n);
void	ft_mtmigrate(t_mt **src, t_mt **dest);
void	ft_mtpush(t_mt **src, t_mt **dest);
void	ft_mtpush_back(t_mt **src, t_mt **dest);
void	ft_mtrotate(t_mt **list);
void	ft_mtreverse_rotate(t_mt **list);
void	ft_mtswap(t_mt **list);
void	ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos);
void	ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node);
void	ft_mtreplace_all(t_mt **list, t_mt **replace);

#endif // LIST_H