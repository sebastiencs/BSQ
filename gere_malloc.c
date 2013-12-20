/*
** gere_malloc.c for bsq in /home/chapui_s/travaux/bsq/bsq_malloc
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec  4 12:43:59 2013 chapui_s
** Last update Sun Dec  8 18:10:10 2013 chapui_s
*/

#include <stdlib.h>
#include "bsq.h"

void	free_ptr(unsigned int **ptr1, unsigned int **ptr2, char **tmp)
{
  if (*ptr1)
    free(*ptr1);
  if (*ptr2)
    free(*ptr2);
  if (*tmp)
    free(*tmp);
}

int	put_bad_alloc(char *file)
{
  my_putstr_error(file);
  my_putstr_error(": could not alloc => can't disp the map\n");
  return (-1);
}
