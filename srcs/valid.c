#include <stdlib.h>
#include "lemin.h"

static void	put_in_anthill(t_anthill ***anthill, t_anthill *new)
{
  t_anthill	*tmp;

  tmp = **anthill;
  if (**anthill == NULL)
    {
      **anthill = new;
      return ;
    }
  tmp = **anthill;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
}

static int	check_if_room_valid(char **tab,
				     t_anthill *new,
				     int *flag)
{
  if (wordtab_count(tab) != 3 || check_if_nbr(tab[1]) == 0 ||
      check_if_nbr(tab[2]) == 0)
    return (FAILURE);
  if ((new->name = my_strdup(tab[0])) == NULL)
    return (my_perror(MALLOC_FAILED));
  new->pos.x = my_getnbr(tab[1]);
  new->pos.y = my_getnbr(tab[2]);
  new->empty = EMPTY;
  new->occuped = NOT_OCCUPED;
  new->flag = *flag;
  new->nb_pipe = 0;
  new->to_malloc = -1;
  new->range = 0;
  new->in_a_way = NO;
  new->next = NULL;
  *flag = NONE;
  return (SUCCESS);
}

int		room_valid(char **tab, t_anthill **anthill, int *flag)
{
  t_anthill	*new;

  if ((new = malloc(sizeof(t_anthill))) == NULL)
    return (my_perror(MALLOC_FAILED));
  if ((check_if_room_valid(tab, new, flag)) == FAILURE)
    {
      free(new);
      return (FAILURE);
    }
  put_in_anthill(&anthill, new);
  return (SUCCESS);
}

int		pipe_valid(char **tab,
			   t_list_pipe **tmp_pipe,
			   t_anthill **anthill)
{
  t_list_pipe	*new;

  if (my_strcmp(tab[0], tab[1]) == 1)
    return (SUCCESS);
  if ((new = malloc(sizeof(t_list_pipe))) == NULL)
    return (my_perror(MALLOC_FAILED));
  if (check_if_pipe_valid(tab, anthill, tmp_pipe, new) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
