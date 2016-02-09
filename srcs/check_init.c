#include <unistd.h>
#include "lemin.h"

int	is_pipe_exist(t_infos *infos)
{
  int	is_ok;
  int	i;

  i = 0;
  is_ok = SUCCESS;
  if (infos->anthill == NULL || infos->anthill->pipes == NULL)
    return (FAILURE);
  while (i <= infos->anthill->nb_pipe)
    {
      if (infos->anthill->pipes[i] == NULL && i != infos->anthill->nb_pipe)
	{
	  is_ok = FAILURE;
	  write(2, "pipe ", 5);
	  my_putnbr(i, 2);
	  write(2, " doesn't exit. Pointer NULL\n", 28);
	}
      i++;
    }
  return (is_ok);
}

int	is_infos_exist(t_infos *infos)
{
  if (infos == NULL)
    {
      write(2, "error : infos isn't initialisate. Pointer NULL\n", 47);
      return (FAILURE);
    }
  if (infos->anthill == NULL || infos->first == NULL || infos->end == NULL)
    {
      write(2, "problem in the initialisation : \n", 33);
      if (infos->anthill == NULL)
	write(2, "\tanthil isn't exist. Pointer NULL\n", 34);
      if (infos->first == NULL)
	write(2, "\tfirst isn't exist. Pointer NULL\n", 32);
      if (infos->end == NULL)
	write(2, "\tend isn't exist. Pointer NULL\n", 30);
      return (FAILURE);
    }
  return (SUCCESS);
}

int	check_init(t_infos *infos)
{
  if (is_pipe_exist(infos) == -1 ||
      is_infos_exist(infos))
    return (FAILURE);
  return (SUCCESS);
}
