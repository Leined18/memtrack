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
}				t_stack;

#endif // MTSTRUCTS_H