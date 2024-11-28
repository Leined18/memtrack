
#ifndef MEM_H
# define MEM_H

# include "libft.h"
# include "list.h"

t_mt	*ft_mtzip(t_mt **lst);
t_mt	*ft_mtunzip(void **data, size_t size);
t_mt	*ft_mtnew(const char *key, void *data, t_data_type type);
t_mt	*ft_mtnew_chaos(void *data);
void	ft_mtfree(t_mt *mt);
void	ft_mtpush_data(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtpush_data_back(t_mt **lst, const char *key, void *data,
			t_data_type type);
void	ft_mtremove_data(t_mt **lst, void *data, int (*cmp)(), size_t n);
void	ft_mtclear(t_mt **lst);
void	ft_mterase(t_mt **lst);
void	ft_mtdel_data(void **data);
void	ft_mtdel_list(void **data);
void	ft_mtreplace_all_data(t_mt **lst, void *new_data);
void	ft_mtreplace_data(t_mt *list, void *to_replace, void *new_data,
			int (*cmp)(), size_t n);

#endif // MEM_H