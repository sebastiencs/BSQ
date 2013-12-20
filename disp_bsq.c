/*
** disp_bsq.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec  3 18:20:13 2013 chapui_s
** Last update Sun Dec  8 19:19:57 2013 chapui_s
*/

#include <stdlib.h>
#include "bsq.h"

static void	print_line(char *tmp, t_max *max, int nb_cols)
{
  int		i;

  i = 1;
  write(1, &tmp[0], max->x_max - max->size);
  while (i++ <= max->size)
    write(1, "x", 1);
  i = max->x_max;
  write(1, &tmp[i], nb_cols - i);
}

int	disp_bsq(char *file, t_max *max, int nb_lines, int nb_cols)
{
  char	*tmp;
  int	fd;
  int	i;

  i = 1;
  if ((nb_cols = go_first_line(file, &fd)) == -1)
    return (-1);
  if ((tmp = (char*)malloc(sizeof(char) * (nb_cols + 1))) == NULL)
    return (put_bad_alloc(file));
  tmp[nb_cols++] = 0;
  while (i <= nb_lines)
  {
    if ((read(fd, tmp, nb_cols)) < 0)
      return (my_putstr_error("error: could not read\n"));
    if (i++ <= max->y_max - max->size || i - 1 > max->y_max)
      write(1, tmp, nb_cols);
    else
      print_line(tmp, max, nb_cols);
  }
  free(tmp);
  return (fd);
}

static void	print_little_line_colors(char *tmp, int x_min, int x_max)
{
  int		i;

  i = x_min;
  while (i < x_max)
  {
    while (tmp[i] == '.' && i < x_max)
      write(1, &tmp[i++], 1);
    while (tmp[i] == 'o' && (i <= x_max))
    {
      write(1, "\033[31;40m", 9);
      while (tmp[i] == 'o')
	write(1, &tmp[i++], 1);
      write(1, "\033[0m", 5);
    }
  }
}

static void	print_line_colors(char *tmp, t_max *max, int nb_cols)
{
  int		i;

  print_little_line_colors(tmp, 0, max->x_max - max->size);
  i = 1;
  write(1, "\033[32;40m", 9);
  while (i++ <= max->size)
    write(1, "x", 1);
  write(1, "\033[0m", 5);
  i = max->x_max;
  print_little_line_colors(tmp, max->x_max, nb_cols - 1);
}

int	disp_bsq_colors(char *file, t_max *max, int nb_lines, int nb_cols)
{
  char	*tmp;
  int	fd;
  int	i;

  i = 1;
  if ((nb_cols = go_first_line(file, &fd)) == -1)
    return (-1);
  if ((tmp = (char*)malloc(sizeof(char) * (nb_cols + 1))) == NULL)
    return (-1);
  tmp[nb_cols++] = 0;
  while (i <= nb_lines)
  {
    if ((read(fd, tmp, nb_cols)) < 0)
      return (my_putstr_error("error: could not read\n"));
    if (i++ <= max->y_max - max->size || i - 1 > max->y_max)
      print_little_line_colors(tmp, 0, nb_cols - 1);
    else
      print_line_colors(tmp, max, nb_cols);
    my_putchar('\n');
  }
  free(tmp);
  return (fd);
}
