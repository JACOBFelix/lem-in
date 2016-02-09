#include <stdlib.h>
#include "lemin.h"

int		get_the_direct(t_infos *info,
			       t_int_list **int_list,
			       unsigned int *i)
{
  int		a;
  t_int_list	*new;

  a = 0;
  while (a < info->anthill->nb_pipe &&
	 info->anthill->pipes[a]->flag != END)
      a++;
  if (a == info->anthill->nb_pipe)
    return (FAILURE);
  if ((new = malloc(sizeof(t_int_list))) == NULL)
    return (my_perror(MALLOC_FAILED));
  new->next = NULL;
  new->prev = NULL;
  new->i = a;
  int_list[*i] = new;
  *i = *i + 1;
  int_list[*i] = NULL;
  return (SUCCESS);
}
