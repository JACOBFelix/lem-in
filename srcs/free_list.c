#include <stdlib.h>
#include "lemin.h"

void		free_anthill(t_anthill *list)
{
  t_anthill	*tmp;

  tmp = list;
  while (list)
    {
      list = list->next;
      free(tmp->name);
      if (tmp->to_malloc != -1)
	free(tmp->pipes);
      free(tmp);
      tmp = list;
    }
}

void		free_tmp_pipe(t_list_pipe *list)
{
  t_list_pipe	*tmp;

  tmp = list;
  while (list)
    {
      list = list->next;
      free(tmp);
      tmp = list;
    }
}
