#include <unistd.h>
#include "lemin.h"

int		my_perror(char *str)
{
  write(2, str, my_strlen(str));
  return (FAILURE);
}

int		check_if_nbr(char *str)
{
  register int	i;

  if (!str || (str[0] == '-' && str[1] == '\0'))
    return (0);
  i = 0;
  if (str[i] == '-')
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9')
    i = i + 1;
  if (str[i] == '\0')
    return (1);
  return (0);
}
int		check_if_only_nbr(char *str)
{
  register int	a;

  if (!str)
    return (0);
  a = (str[0] == '-');
  while (str[a] >= '0' && str[a] <= '9')
    a++;
  return (str[a] == 0);
}
