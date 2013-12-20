/*
** arg.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec  3 19:14:41 2013 chapui_s
** Last update Tue Dec  3 19:17:27 2013 chapui_s
*/

#include "bsq.h"

void	skip_option_disp_file(char **argv, int *i, int nb_files)
{
  while (argv[*i][0] == '-')
    *i = *i + 1;
  if (nb_files > 1)
  {
    my_putstr(argv[*i]);
    my_putstr(":\n");
  }
}
