#include <stdlib.h>

int			my_strcmp(char *s1, char *s2)
{
  register unsigned int	i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (s1[i] && s2[i] &&s1[i] == s2[i])
    i++;
  return ((!s1[i] && !s2[i]) ? (1) : (0));
}
