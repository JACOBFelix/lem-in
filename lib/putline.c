#include "lemin.h"

void	my_putline(char *str, const int fd)
{
  my_putstr(str, fd);
  my_putchar('\n', fd);
}
