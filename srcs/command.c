#include <stdlib.h>
#include "lemin.h"

int		is_command(char *readed)
{
  register int	i;

  if (readed == NULL)
    return (FAILURE);
  if (my_strlen(readed) < 2 || (readed[0] != '#' && readed[1] != '#'))
    return (NONE);
  i = 1;
  while (readed[++i] && readed[i] != '#')
    ;
  if (readed[i] == '#')
    readed[i] = 0;
  while (--i && (readed[i] == ' ' || readed[i] == '\t'))
    readed[i] = 0;
  if (my_strcmp(readed + 2, "end"))
    return (END);
  else if (my_strcmp(readed + 2, "start"))
    return (START);
  return (NONE);
}
