/*
** bsq.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 21:51:13 2013 chapui_s
** Last update Sun Dec  8 21:26:50 2013 chapui_s
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

static inline int	minimum(unsigned int a, unsigned int b,
				unsigned int c)
{
  if (a <= b && a <= c)
    return (a);
  else if (b <= a && b <= c)
    return (b);
  else
    return (c);
}

static int	put_int_tab(char *tmp, unsigned int *ptr1,
			    unsigned int *ptr2, t_max *max)
{
  static int	line;
  unsigned int	size_max;
  unsigned int	i;

  i = 1;
  ((max->new)++ == 1) ? (line = 2) : (0);
  if ((init_first_car(tmp, ptr2, max, line)) != 0)
    return (-1);
  size_max = max->size;
  while (tmp[i] != '\n')
  {
    ptr2[i] = 0;
    if (tmp[i] == '.')
    {
      ptr2[i] = minimum(ptr2[i - 1], ptr1[i - 1], ptr1[i]) + 1;
      if (ptr2[i] > size_max)
	size_max = save_max(max, i, line, ptr2[i]);
    }
    else if (tmp[i] != 'o')
      return (put_bad_caractere(line, tmp[i]));
    ++i;
  }
  ++line;
  return (0);
}

static int	bsq(int fd, int nb_lines, int nb_cols, t_max *max)
{
  char		*tmp;
  unsigned int	*ptr1;
  unsigned int	*ptr2;
  unsigned int	i;

  i = 0;
  tmp = (char*)malloc(sizeof(char) * (nb_cols + 2));
  ptr1 = (int*)malloc(sizeof(int) * (nb_cols + 1));
  ptr2 = (int*)malloc(sizeof(int) * (nb_cols + 1));
  if (tmp == NULL || ptr1 == NULL || ptr2 == NULL)
    return (put_bad_alloc("error"));
  if (init_first_line(fd, ptr1, tmp, max) == -1)
    return (-1);
  while (++i < nb_lines)
   {
    if (read(fd, &tmp[0], nb_cols + 1) != nb_cols + 1)
      return (put_bad_line_len());
    if ((put_int_tab(&tmp[0], ptr1, ptr2, max)) == -1)
      return (-1);
    swap_ptr(&ptr1, &ptr2);
  }
  if (read(fd, &tmp[0], nb_cols + 1) > 0)
    return (put_bad_nb_lines("", ""));
  free_ptr(&ptr1, &ptr2, &tmp);
  return (0);
}

static int	prepare_bsq(char *file, int flag_c)
{
  int		nb_lines;
  int		nb_cols;
  t_max		maximum;
  char		tmp;
  int		fd;

  maximum.size = 0;
  maximum.new = 1;
  if ((nb_lines = get_nb_lines(&fd, file)) == -1)
    return (-1);
  if ((nb_cols = get_nb_cols(file)) == -1)
    return (-1);
  if ((bsq(fd, nb_lines, nb_cols, &maximum)) == -1)
  {
    close(fd);
    return (-1);
  }
  close(fd);
  if (flag_c == 0)
    fd = disp_bsq(file, &maximum, nb_lines, nb_cols);
  else
    fd = disp_bsq_colors(file, &maximum, nb_lines, nb_cols);
  return ((fd == -1) ? (-1) : (close(fd)));
}

int	main(int argc, char **argv)
{
  int	i;
  int	file_actual;
  int	nb_files;
  int	flag_c;

  flag_c = 0;
  if (argc == 1)
    return (put_no_arg());
  if ((flag_c = get_option(argc, argv)) == -1)
    return (-1);
  i = 1;
  file_actual = 1;
  if ((nb_files = get_nb_file(argc, argv)) == 0)
    return (put_no_arg());
  while (file_actual <= nb_files)
  {
    skip_option_disp_file(argv, &i, nb_files);
    if ((prepare_bsq(argv[i++], flag_c)) == -1)
      return (-1);
    if (file_actual++ < nb_files)
      my_putstr("\n");
  }
  return (0);
}
