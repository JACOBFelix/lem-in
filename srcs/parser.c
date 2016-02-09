#include <stdlib.h>
#include "lemin.h"
#include "get_next_line.h"

void		del_com_in_line(char *str)
{
  register int	i;

  i = -1;
  while (str[++i] != '\0' && str[i] != '#')
    ;
  str[i] = 0;
  while (--i > 0 && (str[i] == ' ' || str[i] == '\t'))
    i = 0;
}

static int	parser_ants(t_infos *infos)
{
  char		*readed;
  int		intvalue;

  if ((readed = get_next_line(0)) == NULL ||
      check_if_only_nbr(readed) == 0 ||
      (intvalue = my_getnbr(readed)) < 0)
    return (my_perror(ERROR_ANTS_NB));
  my_putline(readed, 1);
  infos->begin_ants = intvalue;
  infos->remaining_ants = intvalue;
  free(readed);
  return (SUCCESS);
}

int		parser(t_infos *infos)
{
  t_anthill	*anthill;
  t_list_pipe	*tmp_pipe;

  anthill = NULL;
  tmp_pipe = NULL;
  if (parser_ants(infos) != SUCCESS ||
      parser_rooms(&anthill, &tmp_pipe) != SUCCESS ||
      parser_pipes(&tmp_pipe, &anthill) != SUCCESS)
    return (FAILURE);
  if (put_pipe_in_anthill(infos, anthill, tmp_pipe) == FAILURE)
    return (FAILURE);
  if (check_duplicates(infos->first) == FAILURE)
    return (FAILURE);
  free_tmp_pipe(tmp_pipe);
  return (SUCCESS);
}
