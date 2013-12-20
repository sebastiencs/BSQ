/*
** put_error_out.c for bsq in /home/chapui_s/travaux/bsq/bsq_malloc
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec  4 21:28:04 2013 chapui_s
** Last update Wed Dec  4 21:28:51 2013 chapui_s
*/

#include <unistd.h>

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
  return (-1);
}

int	my_putstr_secure_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] && i < 82)
    write(2, &str[i++], 1);
  return (-1);
}

int	put_no_arg(void)
{
  my_putstr_error("./bsq [-c] map1 [map2...]\n");
  return (-1);
}
