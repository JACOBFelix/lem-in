#include "lemin.h"

int		main(void)
{
  t_infos	infos;

  if (parser(&infos) == FAILURE)
    return (1);
  if (check_init(&infos) == FAILURE)
    return (1);
  algo(&infos);
  free_anthill(infos.first);
  return (0);
}
