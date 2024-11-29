
#ifndef MT_H
# define MT_H

# include "libft.h"
# include "list.h"
# include "mem.h"
# include "hash.h"
# include "mt.h"
# include "mtlib.h"
# include "mtstructs.h"
# include "utils.h"

# define LIST_REF 2 // Devuelve la referencia de la lista
# define LIST_PTR 1 // Devuelve el puntero de la lista
# define GC_PTR 3   // Devuelve el puntero del garbage collector
# define GC_REF 4   // Devuelve la referencia del garbage collector
# define CLEAR -1   // Borra todos los elementos de la lista

#endif // MT_H