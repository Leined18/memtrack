
#ifndef MTSTRUCTS_H
# define MTSTRUCTS_H

# include <stdlib.h>

typedef struct s_mt
{
	void		*data;
	size_t		size;
	int			count;
	int			n;
	struct s_mt	*next;
	struct s_mt	*prev;
}				t_mt;

typedef struct s_stack
{
	t_mt		*head;
	t_mt		*tail;
	int			size;
	int			id;
	char		*name;
}				t_stack;

typedef struct s_hash_table
{
	t_stack		**buckets;
	size_t		bucket_count;
}				t_hash_table;

#endif // MTSTRUCTS_H