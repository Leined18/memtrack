#ifndef HASH_H
# define HASH_H

// Define your hash function(s) here
# include "mtstructs.h"

// Define your hash table structure here
size_t			ft_mthash(const char *key, size_t bucket_count);
t_hash_table	*ft_mtnew_hash_table(size_t bucket_count);
int				ft_mthash_insert(t_hash_table *ht, const char *key, void *data,
					t_data_type type);
void			*ft_mthash_find(t_hash_table *ht, const char *key);
void			ft_mtfree_hash_table(t_hash_table *ht);
void			ft_mtprint_hash_table(t_hash_table *ht);
int				ft_mthash_remove(t_hash_table *ht, const char *key);
// Function prototypes

#endif // HASH_H