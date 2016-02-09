#include "lemin.h"

void		put_wordtab(char **wordtab)
{
  register int	i;

  if (!wordtab)
    return ;
  i = -1;
  while (wordtab[++i])
    {
      my_putstr(wordtab[i], 1);
      my_putchar('\n', 1);
    }
}
