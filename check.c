/*
** check.c for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 22:19:35 2013 chapui_s
** Last update Tue Dec  3 15:45:21 2013 chapui_s
*/

int	check_nb_lines(char *str)
{
  int	i;

  i = 0;
  while (str[i] && i < 100)
  {
    if (!(str[i] >= '0' && str[i] <= '9'))
      return (-1);
    i = i + 1;
  }
  return (0);
}
