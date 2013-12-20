/*
** errors.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 22:04:28 2013 chapui_s
** Last update Wed Dec  4 21:29:00 2013 chapui_s
*/

#include <unistd.h>

int	put_bad_file(char *file)
{
  my_putstr_error("error opening file: ");
  my_putstr_error(file);
  my_putstr_error("\n");
  return (-1);
}

int	put_bad_line_len(void)
{
  my_putstr_error(" ==> ERROR <==\n");
  my_putstr_error(" ! size of lines are different !\n");
  my_putstr_error(" ! maybe the map is too short  !\n");
  my_putstr_error(" !     or check the last \\n    !\n");
  return (-1);
}

int	put_bad_caractere(int line, char c)
{
  my_putstr_error(" ! error ! bad caractere on the line ");
  my_putnbr_error(line + 1);
  my_putstr_error(": '");
  my_putchar_error(c);
  my_putstr_error("'\n");
  return (-1);
}

int	put_bad_nb_lines(char *str, char *file)
{
  my_putstr_error(file);
  my_putstr_error(" ==> ERROR <==\n");
  if (str[0] != 0)
  {
    my_putstr_error(" ==> bad caracteres in first line: '");
    my_putstr_secure_error(str);
    my_putstr_error("'\n");
  }
  else
  {
    my_putstr_error(" ! First line doesn't match with number of lines !\n");
  }
  return (-1);
}

int	put_map_empty(void)
{
  my_putstr_error("map empty\n");
  return (-1);
}
