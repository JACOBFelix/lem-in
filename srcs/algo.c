#include <stdlib.h>
#include "lemin.h"

int		algo(t_infos *infos)
{
  t_int_list	**tab;

  if ((tab = djikstra(infos)) == NULL)
    return (FAILURE);
  display_ant(infos, tab, 0);
  return (SUCCESS);
}
