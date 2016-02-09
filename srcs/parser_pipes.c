#include <stdlib.h>
#include "get_next_line.h"
#include "lemin.h"

static int	manage_comment(char *readed)
{
  register int	i;

  if (!readed)
    return (0);
  if (my_isin(readed, '#') == 0)
    return (0);
  i = -1;
  while (readed[++i] != '#')
    ;
  readed[i] = '\0';
  i = -1;
  while (readed[++i])
    if (readed[i] != ' ' && readed[i] != '\t')
      return (0);
  return (1);
}

int		parser_pipes(t_list_pipe **tmp_pipe,
			     t_anthill **anthill)
{
  char		*readed;
  char		**tab;

  while ((readed = get_next_line(0)) != NULL)
    {
      if (manage_comment(readed) == 1)
     	{
      	  free(readed);
      	  continue ;
      	}
      my_putline(readed, 1);
      del_com_in_line(readed);
      if ((tab = my_str_to_wordtab(readed, "-")) == NULL)
	{
	  free(readed);
	  return (my_perror(MALLOC_FAILED));
	}
      free(readed);
      if ((pipe_valid(tab, tmp_pipe, anthill)) == FAILURE)
	{
	  free_wordtab(tab);
	  return (FAILURE);
	}
      free_wordtab(tab);
    }
  return (SUCCESS);
}
