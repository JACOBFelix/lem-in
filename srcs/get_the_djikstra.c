#include <stdlib.h>
#include "lemin.h"

int		get_the_way(t_anthill *nearest_end)
{
  t_anthill	*tmp;
  int		range;
  int		a;

  tmp = nearest_end;
  if (tmp->flag == START)
    return (SUCCESS);
  if ((range = nearest_end->range) == 0)
    return (FAILURE);
  tmp->range = -1;
  tmp = nearest_end;
  a = -1;
  while (++a < tmp->nb_pipe &&
	 tmp->pipes[a] &&
	 tmp->pipes[a]->range != range - 1 &&
	 tmp->pipes[a]->flag != START)
    ;
  if (a == tmp->nb_pipe ||
      !tmp->pipes[a])
    return (FAILURE);
  if (tmp->pipes[a] && tmp->pipes[a]->flag == START)
    return (SUCCESS);
  return (get_the_way(tmp->pipes[a]));
}

static int	put_in_int_list(t_int_list ***int_list,
				int a)
{
  t_int_list	*tmp;
  t_int_list	*s_tmp;

  if ((tmp = malloc(sizeof(t_int_list))) == NULL)
    return (my_perror(MALLOC_FAILED));
  tmp->i = a;
  tmp->next = NULL;
  tmp->prev = **int_list;
  if (**int_list == NULL)
    {
      **int_list = tmp;
      return (SUCCESS);
    }
  s_tmp = **int_list;
  while (s_tmp->next)
    s_tmp = s_tmp->next;
  s_tmp->next = tmp;
  return (SUCCESS);
}

int		get_the_djikstra(t_anthill *anthill,
				 t_int_list **int_list)
{
  t_anthill	*tmp;
  int		a;

  tmp = anthill;
  while (tmp->flag != END)
    {
      a = -1;
      tmp->in_a_way = YES;
      while (++a < tmp->nb_pipe && tmp->pipes[a]->range != -1 &&
	     tmp->pipes[a]->flag != END)
	;
      if (a == tmp->nb_pipe)
	return (FAILURE);
      if ((put_in_int_list(&int_list, a)) == FAILURE)
	return (FAILURE);
      tmp->range = -2;
      tmp = tmp->pipes[a];
    }
  return (SUCCESS);
}
