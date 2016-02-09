#include <stdlib.h>
#include "lemin.h"

int		put_in_list(t_list **list, char **tab)
{
  t_list	*new;

  if (((new = malloc(sizeof(t_list))) == NULL) ||
      ((new->tab = my_dup_tab(tab)) == NULL))
    return (0);
}
