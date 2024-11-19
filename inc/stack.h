#ifndef STACK_H
# define STACK_H

# include "mt.h"
# include "mtlib.h"
# include "mtstructs.h"

t_stack	*ft_stknew(t_mt *lst, char *name);
void	ft_stkpush(t_stack **src, t_stack **dest);
void	ft_stkclear(t_stack **stack);

#endif // STACK_H