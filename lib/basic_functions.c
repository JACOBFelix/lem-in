#include <unistd.h>

int		my_strlen(char *str)
{
  register int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putchar(char c, const int fd)
{
  write(fd, &c, 1);
}

void		my_putstr(char *str, const int fd)
{
  write(fd, str, my_strlen(str));
}

int		my_getnbr(char *str)
{
  register int	i;
  int		nb;
  char		c;

  if (!str)
    return (0);
  i = 0;
  nb = 0;
  c = 1;
  if (str[i] == '-')
    {
      c = -1;
      i = 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    nb = nb * 10 + str[i++] - '0';
  return (nb * c);
}

void		my_putnbr(int nb, const int fd)
{
  int		i;

  i = 1;
  if (nb < 0)
    {
      my_putchar('-', fd);
      nb = -nb;
    }
  while (nb / i > 9)
    i *= 10;
  while (i > 0)
    {
      my_putchar((nb / i) % 10 + 48, fd);
      i /= 10;
    }
}
