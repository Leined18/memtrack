
#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include <stdlib.h>

typedef enum e_data_type
{
	LEAF,
	BRANCH,
}				t_data_type;

typedef struct s_mt
{
	char		*key;
	void		*data;
	t_data_type	type;
	size_t		size;
	int			count;
	struct s_mt	*next;
	struct s_mt	*prev;
	void		(*free_data)(void **);
}				t_mt;

typedef struct s_hash_table
{
	t_mt		**buckets;
	size_t		bucket_count;
	int			(*put)(struct s_hash_table *, const char *, void *,
					t_data_type);
	void		*(*get)(struct s_hash_table *, const char *);
	void		*(*get_data)(struct s_hash_table *, const char *);
	int			(*remove)(struct s_hash_table *, const char *);
	void		(*free_hash)(struct s_hash_table *);
	void		(*print)(struct s_hash_table *);
    int			(*add_child)(struct s_hash_table *, const char *, t_mt *);
}				t_hash_table;

#endif // MTSTRUCTS_H