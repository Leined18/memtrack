#ifndef HASH_H
# define HASH_H
# include "mtstructs.h"

// Define your hash table structure here
typedef struct s_hash_table_methods
{
	int			(*insert)(struct s_hash_table *, const char *, void *,
					t_data_type);
	void		*(*search)(struct s_hash_table *, const char *);
	void		*(*search_data)(struct s_hash_table *, const char *);
	int			(*remove)(struct s_hash_table *, const char *);
	void		(*free_table)(struct s_hash_table *);
	void		(*print)(struct s_hash_table *);
	int			(*add_child)(struct s_hash_table *, const char *, t_mt *);
	void		(*insert_child)(struct s_hash_table *, const char *,
				const char *, void *, t_data_type);
	void		(*replace_key)(struct s_hash_table *, const char *,
				const char *);
	void		(*replace_data)(struct s_hash_table *, const char *, void *,
				t_data_type);
	void		(*replace_node)(struct s_hash_table *, const char *, t_mt *);
	void		(*add)(struct s_hash_table *, t_mt *);
}				t_hash_table_methods;

typedef struct s_hash_table
{
	size_t		bucket_count;
	char		*name;
	t_mt		**buckets;
	t_hash_table_methods methods; // Uso de t_hash_table_methods
}				t_hash_table;
// Function prototypes

// create functions
size_t			ft_mthash(const char *key, size_t bucket_count);
t_hash_table	*ft_mthash_new_table(size_t bucket_count, char *name);

// find functions
void			*ft_mthash_find_node(t_hash_table *ht, const char *key);
void			*ft_mthash_find_data(t_hash_table *ht, const char *key);

// free functions
void			ft_mtfree_hash_table(t_hash_table *ht);
void			ft_mthash_table_free(void **ht);

// print functions
void			ft_mtprint_hash_table(t_hash_table *ht);

// remove functions
int				ft_mthash_remove_node(t_hash_table *ht, const char *key);

// get functions
int				ft_mthash_get_index(t_hash_table *ht, const char *key);

// replace functions
void			ft_mthash_replace_key(t_hash_table *ht, const char *old_key,
					const char *new_key);
void			ft_mthash_replace_data(t_hash_table *ht, const char *key,
					void *new_data, t_data_type type);
void			ft_mthash_replace_node(t_hash_table *ht, const char *key,
					t_mt *node);

// check functions
int				ft_mthash_exists(t_hash_table *ht, const char *key);

// add functions
void			ft_mthash_add_node(t_hash_table *ht, t_mt *node);
int				ft_mthash_add_child(t_hash_table *ht, const char *key,
					t_mt *child);

// count functions
int				ft_mthash_count_data_type(t_hash_table *ht, t_data_type type);
int				ft_mthash_count_node_type(t_hash_table *ht, t_node_type type);

// set functions
void			ft_mthash_set_methods(t_hash_table *ht);

// insert functions
void			ft_mthash_insert_child(t_hash_table *ht, const char *parent_key,
					const char *child_key, void *data, t_data_type type);
int				ft_mthash_insert(t_hash_table *ht, const char *key, void *data,
					t_data_type type);

// hash key functions
char			*ft_mthash_new_original_key(char *key, t_hash_table *ht);

// collect functions
t_mt			*ft_mthash_collect_node_types(t_hash_table *ht,
					t_node_type type);
t_mt			*ft_mthash_collect_data_types(t_hash_table *ht,
					t_data_type type);

#endif // HASH_H