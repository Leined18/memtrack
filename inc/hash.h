#ifndef HASH_H
# define HASH_H

// Define your hash function(s) here
# include "mtstructs.h"

// Define your hash table structure here
size_t			ft_mthash(const char *key, size_t bucket_count);
t_hash_table	*ft_mtnew_hash_table(size_t bucket_count);
int				ft_mthash_insert(t_hash_table *ht, const char *key, void *data,
					t_data_type type);
int				ft_mthash_add_child(t_hash_table *ht, const char *key,
					t_mt *child);
void			*ft_mthash_find_node(t_hash_table *ht, const char *key);
void			*ft_mthash_find_data(t_hash_table *ht, const char *key);
void			ft_mtfree_hash_table(t_hash_table *ht);
void			ft_mthash_table_free(void **ht);
void			ft_mtprint_hash_table(t_hash_table *ht);
int				ft_mthash_remove(t_hash_table *ht, const char *key);
int				ft_mthash_find_index(t_hash_table *ht, const char *key);
void			ft_mthash_replace_key(t_hash_table *ht, const char *old_key,
					const char *new_key);
void			ft_mthash_replace_data(t_hash_table *ht, const char *key,
					void *new_data, t_data_type type);
void			ft_mthash_replace_node(t_hash_table *ht, const char *key,
					t_mt *node);
int				ft_mthash_exists(t_hash_table *ht, const char *key);
void			ft_mthash_add_node(t_hash_table *ht, t_mt *node);

// hash_utils functions
void			ft_mtdel_by_type(void **data, t_data_type type);
void (*ft_mtget_free_data(t_data_type type))(void **);
// Function prototypes

#endif // HASH_H