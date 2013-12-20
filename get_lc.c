/*
** get_lc.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 22:53:55 2013 chapui_s
** Last update Sun Dec  8 19:23:03 2013 chapui_s
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

int	get_nb_lines(int *fd, char *file)
{
  int	i;
  char	nb_lines[15];

  i = 0;
  if ((*fd = open(file, O_RDONLY)) == -1)
    return (put_bad_file(file));
  while (read(*fd, &nb_lines[i], 1) > 0 && nb_lines[i] != '\n' && i < 15)
    i = i + 1;
  if (i == 14)
    return (my_putstr_error("error: bad number on first line\n"));
  nb_lines[i] = 0;
  if (check_nb_lines(nb_lines) == -1 || i == 0)
  {
    close(*fd);
    return (put_bad_nb_lines(nb_lines, file));
  }
  return (my_atoi(nb_lines));
}

int	get_nb_cols(char *file)
{
  int	fd;
  char	tmp;
  int	i;

  i = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    return (put_bad_file(file));
  while (read(fd, &tmp, 1) > 0 && tmp != '\n');
  while (read(fd, &tmp, 1) > 0 && tmp != '\n')
    i = i + 1;
  if ((close(fd)) == -1)
    return (my_putstr_error("error: could not close file\n"));
  return (i);
}

int	go_first_line(char *file, int *fd)
{
  char	tmp;
  int	i;

  i = 0;
  tmp = 0;
  if ((*fd = open(file, O_RDONLY)) == -1)
    return (put_bad_file(file));
  while (read(*fd, &tmp, 1) > 0 && tmp != '\n');
  tmp = 0;
  while (read(*fd, &tmp, 1) > 0 && tmp != '\n')
    i = i + 1;
  if ((close(*fd)) == -1)
    return (my_putstr_error("error: could not close file\n"));
  if ((*fd = open(file, O_RDONLY)) == -1)
    return (put_bad_file(file));
  tmp = 0;
  while (read(*fd, &tmp, 1) > 0 && tmp != '\n');
  return (i);
}

int	get_option(int argc, char **argv)
{
  int	i;
  int	flag_c;

  i = 1;
  flag_c = 0;
  while (i < argc)
  {
    if (argv[i][0] == '-')
    {
      if (argv[i][1] == 'c')
	flag_c = 1;
      else if (argv[i][1] == 'g')
	return (gen_map(argc, argv));
      else
      {
	my_putstr_error("./bsq: invalid option -- '");
	my_putchar_error(argv[i][1]);
	my_putstr_error("\'\n");
	return (-1);
      }
    }
    i = i + 1;
  }
  return (flag_c);
}

int	get_nb_file(int argc, char **argv)
{
  int	i;
  int	nb_files;

  i = 1;
  nb_files = 0;
  while (i < argc)
  {
    if (argv[i][0] != '-')
      nb_files = nb_files + 1;
    i = i + 1;
  }
  return (nb_files);
}
