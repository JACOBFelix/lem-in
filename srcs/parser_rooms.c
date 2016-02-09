#include <stdlib.h>
#include "lemin.h"
#include "get_next_line.h"

static int	is_comment(char *readed)
{
  int		len;

  if (readed == NULL)
    return (0);
  len = my_strlen(readed);
  if (len > 0 && readed[0] == '#')
    return ((len > 1 && readed[1] == '#') ? (0) : (1));
  return (0);
}

static int	get_parsed_line(char *readed,
				t_anthill **anthill,
				t_list_pipe **tmp_pipe)
{
  char		**tab;
  static int	flag = NONE;

  if (flag == NONE &&
      (flag = is_command(readed)) != NONE)
    return (SUCCESS);
  del_com_in_line(readed);
  if ((tab = my_str_to_wordtab(readed, " \t")) == NULL)
    return (my_perror(MALLOC_FAILED));
  if ((room_valid(tab, anthill, &flag)) == SUCCESS)
    {
      free_wordtab(tab);
      return (SUCCESS);
    }
  free_wordtab(tab);
  if ((tab = my_str_to_wordtab(readed, "-")) == NULL)
    return (my_perror(MALLOC_FAILED));
  if ((pipe_valid(tab, tmp_pipe, anthill)) == SUCCESS)
    {
      free_wordtab(tab);
      return (IS_A_PIPE);
    }
  free_wordtab(tab);
  return (FAILURE);
}

int		parser_rooms(t_anthill **anthill,
			     t_list_pipe **tmp_pipe)
{
  char		*readed;
  int	        i;

  while ((readed = get_next_line(0)) != NULL)
    {
      if (is_comment(readed))
	{
	  free(readed);
	  continue ;
	}
      my_putline(readed, 1);
      i = get_parsed_line(readed, anthill, tmp_pipe);
      free(readed);
      if (i == FAILURE)
	return (FAILURE);
      if (i == IS_A_PIPE)
	return (SUCCESS);
    }
  return (my_perror(NO_PIPE));
}
