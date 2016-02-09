#include "lemin.h"

static int	how_many_ant_in_end(t_infos *infos)
{
  if (infos->begin_ants == infos->end->nb_ant)
    return (1);
  return (0);
}

static void	my_put_ant(int nb,
			   char *str)
{
  my_putchar('P', 1);
  my_putnbr(nb, 1);
  my_putchar('-', 1);
  my_putstr(str, 1);
  my_putchar(' ', 1);
}

static void	move_ant(t_anthill *ant_tmp,
			 t_int_list *int_tmp,
			 int i)
{
  if (ant_tmp->flag != END)
    move_ant(ant_tmp->pipes[int_tmp->i], int_tmp->next,
	     ant_tmp->occuped);
  ant_tmp->occuped = i;
  if (ant_tmp->flag == END && ant_tmp->occuped > 0)
    ant_tmp->nb_ant++;
  if (ant_tmp->occuped != 0)
    my_put_ant(ant_tmp->occuped, ant_tmp->name);
}

static int	size_int_list(t_int_list *int_list)
{
  int		i;
  t_int_list	*tmp;

  tmp = int_list;
  i = 0;
  while (tmp)
    {
      i = i + 1;
      tmp = tmp->next;
    }
  return (i);
}

void		display_ant(t_infos *infos,
			    t_int_list **int_list,
			    int a)
{
  t_anthill	*ant_tmp;
  t_int_list	*int_tmp;
  int		i;

  infos->end->nb_ant = 0;
  infos->remaining_ants = infos->begin_ant;
  if (!int_list || !int_list[0])
    return ;
  while (how_many_ant_in_end(infos) == 0)
    {
      i = -1;
      while (int_list[++i] && (size_int_list(int_list[i]) <
			     infos->remaining_ants || i == 0))
	{
	  ant_tmp = infos->anthill;
	  int_tmp = int_list[i];
	  a = a + 1;
	  if (a <= infos->begin_ants)
	    move_ant(ant_tmp->pipes[int_tmp->i], int_tmp->next, a);
	  else
	    move_ant(ant_tmp->pipes[int_tmp->i], int_tmp->next, 0);
	  infos->remaining_ants = infos->remaining_ants - 1;
	}
      my_putchar('\n', 1);
    }
}
