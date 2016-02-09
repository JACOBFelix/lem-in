#include <stdlib.h>
#include "lemin.h"

static unsigned int	my_strcount(char *str, char *c)
{
  unsigned int		i;
  unsigned int		j;
  unsigned int		count;

  count = 0;
  i = -1;
  while (str[++i])
    {
      j = -1;
      while (c[++j])
	if (str[i] == c[j])
	  ++count;
    }
  return (count);
}

static void	put_2_0(unsigned int *a, unsigned int *b)
{
  *a = 0;
  *b = 0;
}

char		**my_str_to_wordtab(char *str, char *c)
{
  unsigned int	i;
  unsigned int	j;
  unsigned int	r;
  unsigned int	len;
  char		**wordtab;

  if ((wordtab = malloc((my_strcount(str, c) + 3) * sizeof(char *))) == NULL)
    return (NULL);
  put_2_0(&i, &j);
  len = my_strlen(str);
  while (i < len)
    {
      while (my_isin(c, str[i]))
	i++;
      r = i;
      while (str[i] && !my_isin(c, str[i]))
	i++;
      str[i++] = 0;
      if ((wordtab[j++] = my_strdup(str + r)) == NULL)
	return (NULL);
      while (i < len && my_isin(c, str[i]))
	i++;
    }
  wordtab[j] = NULL;
  return (wordtab);
}

int		free_wordtab(char **wordtab)
{
  int		i;

  i = -1;
  while (wordtab[++i] != NULL)
    free(wordtab[i]);
  free(wordtab);
  return (0);
}

int		wordtab_count(char **wordtab)
{
  int		i;

  if (wordtab == NULL)
    return (-1);
  i = 0;
  while (wordtab[i] != NULL)
    ++i;
  return (i);
}
