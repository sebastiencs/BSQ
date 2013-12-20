/*
** utils2.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec  3 20:02:49 2013 chapui_s
** Last update Sun Dec  8 19:33:00 2013 chapui_s
*/

#include "bsq.h"

int	init_first_line(int fd, int *first, char *tmp, t_max *max)
{
  int	i;
  int	size_max;

  i = 0;
  size_max = max->size;
  while (read(fd, &tmp[i], 1) > 0 && tmp[i] != '\n')
  {
    first[i] = 0;
    if (tmp[i] == '.')
    {
      first[i] = 1;
      if (size_max <= 0)
	size_max = save_max(max, i, 1, 1);
    }
    else if (tmp[i] != 'o')
      return (put_bad_caractere(1, tmp[i]));
    i = i + 1;
  }
  if (tmp[i] == 0)
    return (put_bad_line_len());
  return (0);
}

int	init_first_car(char *tmp, int *ptr2, t_max *max, int line)
{
  ptr2[0] = 0;
  if (tmp[0] == '.')
    ptr2[0] = 1;
  else if (tmp[0] != 'o' && tmp[0] != '\n')
    return (put_bad_caractere(line, tmp[0]));
  if (max->size <= 0 && ptr2[0] == 1)
    max->size = save_max(max, 0, line, ptr2[0]);
  return (0);
}

void		swap_ptr(unsigned int **ptr1, unsigned int **ptr2)
{
  unsigned int	*swap;

  swap = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = swap;
}

int	save_max(t_max *max, int i, int line, int current)
{
  max->size = current;
  max->x_max = i + 1;
  max->y_max = line;
  return (current);
}
