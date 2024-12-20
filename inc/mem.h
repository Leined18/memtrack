
#ifndef MEM_H
# define MEM_H

# include "libft.h"
# include "list.h"

t_mt	*ft_mtzip(t_mt **lst);
t_mt	*ft_mtunzip(void **data, size_t size);
t_mt	*ft_mtnew(const char *key, void *data, t_data_type type);
t_mt	*ft_mtdup(t_mt *src);
t_mt	*ft_mtnew_chaos(void *data);
void	ft_mtfree(t_mt *mt);
void	ft_mtpush_data(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtpush_data_back(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtremove_data(t_mt *lst, char *key);
void	ft_mtclear(t_mt **lst);
void	ft_mterase(t_mt **lst);
void	ft_mtdel_data(void **data);
void	ft_mtdel_list(void **data);
void	ft_mtreplace_all_data(t_mt **lst, void *new_data, t_data_type type);

#endif // MEM_H