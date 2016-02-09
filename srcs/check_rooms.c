#include <stdlib.h>
#include "lemin.h"

static int	is_same(t_pos *a, t_pos *b)
{
  return ((a->x == b->x && a->y == b->y) ? (1) : (0));
}

static int	check_same_room(t_anthill *tmp, t_anthill *foreach, int *count)
{
  if ((is_same(&tmp->pos, &foreach->pos) &&
       my_strcmp(tmp->name, foreach->name) &&
       *count++ > 0) ||
      (is_same(&tmp->pos, &foreach->pos) &&
       !my_strcmp(tmp->name, foreach->name)) ||
      (!is_same(&tmp->pos, &foreach->pos) &&
       my_strcmp(tmp->name, foreach->name)))
    return (my_perror(DOUBLE_ROOM));
  return (SUCCESS);
}

static int	check_double_start_end(t_anthill *anthill)
{
  register int	end;
  register int	start;
  t_anthill	*tmp;

  end = 0;
  start = 0;
  tmp = anthill;
  while (tmp)
    {
      if (tmp->flag == START)
	{
	  if (start++ > 0)
	    return (my_perror(DOUBLE_START));
	}
      else if (tmp->flag == END)
	{
	  if (end ++ > 0)
	    return (my_perror(DOUBLE_END));
	}
      tmp = tmp->next;
    }
  return ((start == 0) ? (my_perror(ERROR_NO_START)) : (SUCCESS));
}

int		check_duplicates(t_anthill *anthill)
{
  int		count;
  t_anthill	*tmp;
  t_anthill	*foreach;

  if (check_double_start_end(anthill) != SUCCESS)
    return (FAILURE);
  tmp = anthill;
  while (tmp != NULL)
    {
      foreach = anthill;
      count = 0;
      while (foreach != NULL)
	{
	  if (check_same_room(tmp, foreach, &count) != SUCCESS)
	    return (FAILURE);
	  foreach = foreach->next;
	}
      tmp = tmp->next;
    }
  return (SUCCESS);
}
