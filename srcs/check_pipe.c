#include <stdlib.h>
#include "lemin.h"

static void	put_in_tmp_pipe(t_list_pipe ***tmp_pipe, t_list_pipe *new)
{
  t_list_pipe	*tmp;

  tmp = **tmp_pipe;
  if (**tmp_pipe == NULL)
    {
      **tmp_pipe = new;
      return ;
    }
  tmp = **tmp_pipe;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
}

static int	check_if_pipe_in_anthill(char *str, t_anthill **anthill)
{
  t_anthill	*tmp;

  tmp = *anthill;
  if (*anthill == NULL)
    return (FAILURE);
  while (tmp && (my_strcmp(str, tmp->name) == 0))
    tmp = tmp->next;
  if (tmp == NULL)
    return (FAILURE);
  tmp->nb_pipe = tmp->nb_pipe + 1;
  return (SUCCESS);
}

int		check_if_pipe_valid(char **tab,
				    t_anthill **anthill,
				    t_list_pipe **tmp_pipe,
				    t_list_pipe *new)
{
  if ((wordtab_count(tab) != 2) ||
      check_if_pipe_in_anthill(tab[0], anthill) == FAILURE ||
      check_if_pipe_in_anthill(tab[1], anthill) == FAILURE)
    return (my_perror(INVALID_PIPE));
  if (((new->first = my_strdup(tab[0])) == NULL) ||
      ((new->second = my_strdup(tab[1])) == NULL))
    return (my_perror(MALLOC_FAILED));
  new->next = NULL;
  put_in_tmp_pipe(&tmp_pipe, new);
  return (SUCCESS);
}
