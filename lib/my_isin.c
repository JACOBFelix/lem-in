int	my_isin(char *str, char c)
{
  int	i;

  i = -1;
  while (str[++i])
    if (str[i] == c)
      return (1);
  return (0);
}
