#include <stdlib.h>
#include "lemin.h"

void		check_useless(t_anthill *anthill)
{
  t_anthill	*tmp;

  tmp = anthill;
  while (tmp)
    {
      if (tmp->nb_pipe < 2 && tmp->flag == NONE)
	tmp->flag = USELESS;
      tmp = tmp->next;
    }
}

static void	init_first_room(t_infos *infos)
{
  int		i;
  t_anthill	*tmp;

  tmp = infos->first;
  while (tmp)
    {
      tmp->range = 0;
      tmp->djikstra_close = NO;
      tmp = tmp->next;
    }
  i = -1;
  while (++i < infos->anthill->nb_pipe &&
	 infos->anthill->pipes[i])
    if (infos->anthill->pipes[i]->in_a_way == NO)
      infos->anthill->pipes[i]->range = 1;
}

static int	djikstra_is_over(t_anthill *anthill_list)
{
  t_anthill	*tmp;

  tmp = anthill_list;
  while (tmp)
    {
      if (tmp->in_a_way == YES)
	{
	  tmp = tmp->next;
	  continue ;
	}
      if (tmp->djikstra_close == NO &&
	  tmp->range > 0)
	return (NO);
      tmp = tmp->next;
    }
  return (YES);
}

static void	put_the_djikstra(int i,
				 t_anthill *anthill_list)
{
  t_anthill	*tmp;
  int		a;

  tmp = anthill_list;
  while (tmp)
    {
      if (tmp->range == i && tmp->djikstra_close == NO &&
	  tmp->in_a_way == NO)
	{
	  a = -1;
	  while (++a < tmp->nb_pipe &&
		 tmp->pipes[a])
	      if ((tmp->pipes[a]->range > i ||
		  tmp->pipes[a]->range == 0) &&
		  tmp->pipes[a]->flag != START &&
		  tmp->pipes[a]->in_a_way == NO)
		tmp->pipes[a]->range = i + 1;
	  tmp->djikstra_close = YES;
	}
      if (tmp->range < i && tmp->range > 0 && tmp->djikstra_close == NO &&
	  tmp->in_a_way == NO)
	put_the_djikstra(tmp->range, anthill_list);
      tmp = tmp->next;
    }
}

t_int_list	*load_the_djikstra(t_infos *infos)
{
  int		i;
  t_int_list	*int_list;

  int_list = NULL;
  init_first_room(infos);
  i = 1;
  while (djikstra_is_over(infos->first) == NO)
    put_the_djikstra(i++, infos->first);
  if ((get_the_way(infos->end) == FAILURE) ||
      (get_the_djikstra(infos->anthill, &int_list)) == FAILURE)
    return (NULL);
  return (int_list);
}
