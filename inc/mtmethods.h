#ifndef MTMETHODS_H
# define MTMETHODS_H

# include "libft.h"
# include "mtstructs.h"

// Struct Definition
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

// ==================== Memory Management ====================
void			ft_mtfree(t_mt *mt);
void			ft_mtclear(t_mt **lst);
void			ft_mterase(t_mt **lst);
void			ft_mtdel_data(void **data);
void			ft_mtdel_list(void **data);

// ==================== Count Functions ====================
int				ft_mtcount_data_type(t_mt *node, t_data_type type);
int				ft_mtcount_node_type(t_mt *node, t_node_type type);
int				ft_mtcount_state(t_mt *node, int state);
size_t			ft_mtcount_node(t_mt *lst);
int				ft_mtsize(t_mt *lst);

// ==================== Iteration and Set Functions ====================
void			ft_mtiter(t_mt *lst, void *param, void (*func)(t_mt *, void *));
void			ft_mtprint(t_mt *lst, int b, char *c);
void			ft_mtset_to_free(t_mt *mt, int to_free);
void			ft_mtset_free_func(t_mt *node, void (*free_func)(void **));

// ==================== Movement Functions ====================
void			ft_mtmigrate_back(t_mt **src, t_mt **dest);
void			ft_mtmigrate(t_mt **src, t_mt **dest);
void			ft_mtpush(t_mt **src, t_mt **dest);
void			ft_mtpush_back(t_mt **src, t_mt **dest);
void			ft_mtrotate(t_mt **list);
void			ft_mtreverse_rotate(t_mt **list);
void			ft_mtswap(t_mt **list);

// ==================== Deletion Functions ====================
void			ft_mtpop_back(t_mt **lst);
void			ft_mtpop(t_mt **lst);

// ==================== Insertion Functions ====================
void			ft_mtinsert_index(t_mt **list, t_mt *new_node, int pos);
void			ft_mtreplace(t_mt **list, t_mt *node, t_mt *new_node);
void			ft_mtreplace_all(t_mt **list, t_mt **replace);
void			ft_mtadd_back(t_mt **lst, t_mt *new);
void			ft_mtadd_front(t_mt **lst, t_mt *new);
int				ft_mtadd_child(t_mt *parent, t_mt *child);

// ==================== Check Functions ====================
int				ft_mtexists_mt(t_mt *root, const char *key);

// ==================== Key Management ====================
char			*ft_mtnew_original_key(char *key, t_mt *node);

// ==================== Filter Functions ====================
void			ft_mtfilter(t_mt *lst, void *param, int (*predicate)(t_mt *,
						void *), t_mt **result);

// ==================== Fold Functions ====================
int				ft_mtfold(t_mt *lst, void *param, int (*func)(t_mt *, void *));

// ==================== Collection Functions ====================
t_mt			*ft_mtcollect_node_type(t_mt *mt, t_node_type type);
t_mt			*ft_mtcollect_data_type(t_mt *mt, t_data_type type);
t_mt			*ft_mtcollect_state(t_mt *mt, int state);

// ==================== Search Functions ====================
t_mt			*ft_mtsearch(t_mt *lst, void *, int (*predicate)(t_mt *,
						void *));
t_mt			*ft_mtsearch_key(t_mt *root, const char *key);
t_mt			*ft_mtlast(t_mt *lst);
t_mt			*ft_mtfirst(t_mt *lst);
t_mt			*ft_mtroot(t_mt *lst);

// ==================== Utility Functions ====================
t_mt			*ft_mtzip(t_mt **lst);
t_mt			*ft_mtunzip(void **data, size_t size);
t_mt			*ft_mtnew(const char *key, void *data, t_data_type type);
t_mt			*ft_mtdup(t_mt *src);
t_mt			*ft_mtnew_chaos(void *data);
void			ft_mtpush_data(t_mt **lst, const char *key, void *data,
					t_data_type type);
void			ft_mtpush_data_back(t_mt **lst, const char *key, void *data,
					t_data_type type);
void			ft_mtremove_data(t_mt *lst, char *key);
void			ft_mtreplace_all_data(t_mt **lst, void *new_data,
					t_data_type type);

#endif // MTMETHODS_H
