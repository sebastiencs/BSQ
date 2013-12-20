/*
** gen_map.c for bsq in /home/chapui_s/travaux/bsq/bsq_malloc
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Dec  5 19:59:23 2013 chapui_s
** Last update Sun Dec  8 19:45:23 2013 chapui_s
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"

static int	get_rand(int y)
{
  int		fd;
  int		nb;
  float		nb2;

  if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
    return (my_putstr_error("error: could not open /dev/urandom\n"));
  if ((read(fd, &nb, 1)) == -1)
    return (my_putstr_error("error: could not read /dev/urandom\n"));
  if ((close(fd)) == -1)
    return (my_putstr_error("error: could not close /dev/urandom\n"));
  if (nb < 0)
    nb = -nb;
  nb = nb % 100;
  nb2 = (float)nb / 100;
  return (nb2 * y + 0.5);
}

static int	print_it(int x, int y, int density)
{
  int		tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i++ < y)
  {
    j = 0;
    while (j++ < x)
    {
      if ((tmp = get_rand(y) * 2) < 0)
	return (-1);
      else if (tmp < density)
	write(1, "o", 1);
      else
	write(1, ".", 1);
    }
    my_putchar('\n');
  }
  return (0);
}

static int	check_bad_car(char *str)
{
  int		i;

  i = 0;
  while (str[i])
  {
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (-1);
    i = i + 1;
  }
  return (0);
}

int	gen_map(int argc, char **argv)
{
  int	x;
  int	y;
  int	density;

  if (argc != 5)
    return (my_putstr_error("./bsq -g x y density\n"));
  if (check_bad_car(argv[2]) == -1 || check_bad_car(argv[3]) == -1
      || check_bad_car(argv[4]) == -1)
    return (my_putstr_error("./bsq -g x y density\n"));
  x = my_atoi(argv[2]);
  y = my_atoi(argv[3]);
  density = my_atoi(argv[4]);
  my_putnbr(y);
  my_putchar('\n');
  print_it(x, y, density);
  return (-1);
}
