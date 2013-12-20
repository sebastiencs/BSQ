/*
** utils.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 21:51:31 2013 chapui_s
** Last update Tue Dec  3 20:05:05 2013 chapui_s
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}

unsigned int	my_strlen_secure(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i] && i < 82)
    i = i + 1;
  return (i);
}

void	my_putnbr_error(int nb)
{
  if (nb >= 10)
    my_putnbr_error(nb / 10);
  my_putchar_error((nb % 10) + '0');
}
