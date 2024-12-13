
#ifndef MEM_H
# define MEM_H

# include "libft.h"
# include "list.h"

t_mt	*ft_mtzip(t_mt **lst);
t_mt	*ft_mtunzip(void **data, size_t size);
t_mt	*ft_mtnew(const char *key, void *data, t_data_type type);
t_mt	*ft_mtdup(t_mt *src);
t_mt	*ft_mtnew_chaos(void *data);

// disconnect
void	*ft_mtdisconnect_left(t_mt **node);
void	*ft_mtdisconnect_right(t_mt **node);
void	*ft_mtdisconnect_parent(t_mt **node);
void	*ft_mtdisconnect_child(t_mt **node);
t_mt	*ft_mtdisconnect(t_mt **node);

// connect
void	*ft_mtconnect_left(t_mt **node, t_mt *left);
void	*ft_mtconnect_right(t_mt **node, t_mt *right);
void	*ft_mtconnect_parent(t_mt **node, t_mt *parent);
void	*ft_mtconnect_child(t_mt **node, t_mt *child);

void	ft_mtpush_data(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtpush_data_back(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtremove_data(t_mt *lst, char *key);
int		ft_mtclear(t_mt **lst);
void	ft_mterase(t_mt **lst);
void	ft_mtfree(t_mt **mt);
void	ft_mtdel_data(void **data);
void	ft_mtdel_list(void **data);
void	ft_mtreplace_all_data(t_mt **lst, void *new_data, t_data_type type);

#endif // MEM_H