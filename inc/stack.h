#ifndef STACK_H
# define STACK_H

# include "mt.h"
# include "mtlib.h"
# include "mtstructs.h"

t_stack	*ft_stknew(t_mt *lst, char *name);
void	ft_stkpush(t_stack **src, t_stack **dest);
void	ft_stkclear(t_stack **stack);
void	ft_stkpop(t_stack **stack);
t_stack	*ft_stkzip(t_stack **stack);
t_stack	*ft_stkunzip(t_stack **stack);
void	ft_stkadd_mt_back(t_stack **stack, t_mt *new);
void	ft_stkadd_mtlist_back(t_stack **stack, t_mt **new);
void	ft_stkadd_stk_back(t_stack **stack, t_stack *new);
void	ft_stkmigrate_back(t_stack **src, t_stack **dest);
void	ft_stkprint(t_stack *stack, int type, char *c);

#endif // STACK_H