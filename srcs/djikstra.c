#include <stdlib.h>
#include "lemin.h"

static int	max_way(t_infos *info)
{
  int		nb_way;

  if (info->anthill->nb_pipe < info->end->nb_pipe)
    nb_way = info->anthill->nb_pipe;
  else
    nb_way = info->end->nb_pipe;
  return (nb_way);
}

static void	reset_pos(t_infos *info)
{
  t_anthill	*tmp;

  tmp = info->first;
  while (tmp)
    {
      tmp->range = 0;
      tmp->djikstra_close = NO;
      tmp = tmp->next;
    }
}

static void	close_room(t_infos *info)
{
  t_anthill	*tmp;

  tmp = info->anthill;
  while (tmp)
    {
      if (tmp->range == -2)
	tmp->in_a_way = YES;
      tmp = tmp->next;
    }
}

static int     	find_a_djikstra(t_infos *info,
				 t_int_list **int_list,
				 int i)
{
  reset_pos(info);
  if ((int_list[i] = load_the_djikstra(info)) == NULL)
    return (FAILURE);
  close_room(info);
  return (SUCCESS);
}

t_int_list	**djikstra(t_infos *info)
{
  t_int_list	**int_list;
  unsigned int 	nb_way;
  unsigned int 	i;

  if ((nb_way = max_way(info)) == 0)
    return (NULL);
  if ((int_list = malloc(sizeof(t_int_list *) * (nb_way + 1))) == NULL)
    return (NULL);
  i = 0;
  if (get_the_direct(info, int_list, &i) == SUCCESS)
    return (int_list);
  while (i < nb_way && find_a_djikstra(info, int_list, i++) == SUCCESS)
    ;
  if (i == 0)
    return (NULL);
  int_list[i] = NULL;
  return (int_list);
}
