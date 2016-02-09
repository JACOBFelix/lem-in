#include <stdbool.h>
#include <stdlib.h>
#include "lemin.h"

static int	pipe_malloc(t_anthill *anthill)
{
  if (anthill->to_malloc == -1 &&
      (anthill->pipes = malloc(sizeof(t_anthill *)
			       * (anthill->nb_pipe + 1))) == NULL)
    return (FAILURE);
  anthill->to_malloc = anthill->to_malloc + 1;
  return (SUCCESS);
}

static int	add_pipe_in_anthill(t_anthill *anthill,
				    t_list_pipe *tmp)
{
  t_anthill	*first;
  t_anthill	*second;

  first = anthill;
  second = anthill;
  while (my_strcmp(first->name, tmp->first) == 0)
    first = first->next;
  while (my_strcmp(second->name, tmp->second) == 0)
    second = second->next;
  if (pipe_malloc(first) == FAILURE ||
      pipe_malloc(second) == FAILURE)
    return (FAILURE);
  first->pipes[first->to_malloc] = second;
  second->pipes[second->to_malloc] = first;
  return (SUCCESS);
}

static int	add_exit(t_infos *info)
{
  t_anthill	*tmp;

  tmp = info->first;
  while (tmp && tmp->flag != END)
    tmp = tmp->next;
  if (tmp == NULL)
    return (my_perror(ERROR_NO_END));
  info->end = tmp;
  return (SUCCESS);
}

int		put_pipe_in_anthill(t_infos *info,
				    t_anthill *anthill,
				    t_list_pipe *tmp_pipe)
{
  t_list_pipe	*tmp;
  t_anthill	*tmp_anthill;

  info->first = anthill;
  tmp = tmp_pipe;
  while (tmp)
    {
      if (add_pipe_in_anthill(info->first, tmp) == FAILURE)
	return (FAILURE);
      tmp = tmp->next;
    }
  tmp_anthill = anthill;
  while (tmp_anthill && tmp_anthill->flag != START)
    tmp_anthill = tmp_anthill->next;
  if (tmp_anthill == NULL)
    return (FAILURE);
  info->anthill = tmp_anthill;
  return (add_exit(info));
}
