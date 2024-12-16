#ifndef LIST_H
# define LIST_H

# include "libft.h"
# include "mtstructs.h"

typedef struct s_mt
{
	char		*key;
	void		*data;
	struct s_mt	*parent;
	struct s_mt	*children;
	struct s_mt	*right;
	struct s_mt	*left;
	struct s_mt	*aux;
	void		*ptr_aux;
	t_values	values;
	void		(*free_data)(void **);
}				t_mt;
// memtrack functions

// count functions
int				ft_mtcount_data_type(t_mt *node, t_data_type type);
int				ft_mtcount_node_type(t_mt *node, t_node_type type);
int				ft_mtsize(t_mt *lst);

// iter and set functions
void			ft_mtiter(t_mt *lst, void (*func)(t_mt *));
void			ft_mtprint(t_mt *lst, int b, char *c);
void			ft_mtset_to_free(t_mt *mt, int to_free);
void			ft_mtset_free_func(t_mt *node, void (*free_func)(void **));

// move functions
void			ft_mtmigrate_back(t_mt **src, t_mt **dest);
void			ft_mtmigrate(t_mt **src, t_mt **dest);
void			ft_mtpush(t_mt **src, t_mt **dest);
void			ft_mtpush_back(t_mt **src, t_mt **dest);
void			ft_mtrotate(t_mt **list);
void			ft_mtreverse_rotate(t_mt **list);
void			ft_mtswap(t_mt **list);

// delete functions
void			ft_mtpop_back(t_mt **lst);
void			ft_mtpop(t_mt **lst);

// insert functions
void			ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos);
void			ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node);
void			ft_mtreplace_all(t_mt **list, t_mt **replace);
int				ft_mtadd_child(t_mt *parent, t_mt *child);
void			ft_mtadd_back(t_mt **lst, t_mt *new);
void			ft_mtadd_front(t_mt **lst, t_mt *new);

// check functions
int				ft_mtexists_mt(t_mt *root, const char *key);

// key functions
char			*ft_mtnew_original_key(char *key, t_mt *node);

// filter functions

t_mt			**ft_mtfilter(t_mt *lst, int (*predicate)(t_mt *),
					t_mt **result, int *size);

// fold functions
int				ft_mtfold(t_mt *lst, int (*func)(t_mt *));

// collect functions
t_mt			*ft_mtcollect_node_type(t_mt *mt, t_node_type type);
t_mt			*ft_mtcollect_data_type(t_mt *mt, t_data_type type);
t_mt			*ft_mtcollect_state(t_mt *mt, int state);

// search pointer functions
t_mt			*ft_mtsearch(t_mt *lst, void *, int (*predicate)(t_mt *,
						void *));
t_mt			*ft_mtsearch_key(t_mt *root, const char *key);
t_mt			*ft_mtlast(t_mt *lst);
t_mt			*ft_mtfirst(t_mt *lst);

#endif // LIST_H