
#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include <stdlib.h>

typedef enum e_data_type
{
	STRING,
	LIST
}				t_data_type;

typedef struct s_mt
{
	char		*key;
	void		*data;
	size_t		size;
	int			count;
	t_data_type	type;
	struct s_mt	*next;
	struct s_mt	*prev;
	void		(*free_data)(void **);
}				t_mt;

typedef struct s_hash_table
{
	t_mt		**buckets;
	size_t		bucket_count;
}				t_hash_table;

#endif // MTSTRUCTS_H