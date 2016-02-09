#include <stdlib.h>
#include "lemin.h"

char		*my_strdup(char *str)
{
  char		*cpy;
  unsigned int	i;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc((my_strlen(str) + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = 0;
  return (cpy);
}

char		*my_strndup(char *str, int n)
{
  char		*cpy;
  int		i;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i] && i < n)
    cpy[i] = str[i];
  cpy[i] = 0;
  return (cpy);
}

char		*my_strpdup(char *str, int i, int j)
{
  char		*cpy;
  int		k;

  if (str == NULL)
    return (NULL);
  if ((cpy = malloc((j - i + 1) * sizeof(char))) == NULL)
    return (NULL);
  k = 0;
  while (str[i] && i < j)
    cpy[k++] = str[i++];
  cpy[k] = 0;
  return (cpy);
}

char		*my_strcpy(char *str, char *cpy)
{
  int		i;

  i = -1;
  while (str[++i])
    cpy[i] = str[i];
  cpy[i] = 0;
  return (cpy);
}
