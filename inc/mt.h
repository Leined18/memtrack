
#ifndef MT_H
# define MT_H

# include "hash.h"
# include "libft.h"
# include "mtlib.h"
# include "mtmethods.h"
# include "mtstructs.h"
# include "mtutils.h"

# define LIST_REF 2 // Devuelve la referencia de la lista
# define LIST_PTR 1 // Devuelve el puntero de la lista
# define GC_PTR 3   // Devuelve el puntero del garbage collector
# define GC_REF 4   // Devuelve la referencia del garbage collector
# define CLEAR -1   // Borra todos los elementos de la lista
# define NODE_VISITED ((void *)-1)

#endif // MT_H