/*
** bsq.h for bsq in /home/chapui_s/travaux/bsq
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Dec  2 21:54:01 2013 chapui_s
** Last update Sun Dec  8 19:50:13 2013 chapui_s
*/

#ifndef BSQ_H_
# define BSQ_H_

#include <stddef.h>

typedef struct	s_max
{
  int		x_max;
  int		y_max;
  int		size;
  int		new;
}		t_max;

void		my_putchar(char c);
void		my_putnbr(int nb);
void		my_putstr(char *str);
int		put_no_arg(void);
int		put_bad_file(char *file);
int		check_nb_lines(char *str);
int		put_bad_nb_lines(char *str, char *file);
int		get_nb_lines(int *fd, char *file);
int		get_nb_col(int fd, char **tmp, t_max *max);
void		my_putchar_error(char c);
int		my_putstr_error(char *str);
int		put_map_error(char *str, int line, int i);
int		go_first_line(char *file, int *fd);
unsigned int	my_strlen_secure(char *str);
void		skip_option_disp_file(char **argv, int *i, int nb_files);
int		init_first_line(int fd, int *first, char *tmp, t_max *max);
void		swap_ptr(unsigned int **ptr1, unsigned int **ptr2);
int		save_max(t_max *max, int i, int line, int current);
void		free_ptr(unsigned int **ptr1,
			 unsigned int **ptr2, char **tmp);
int		put_bad_alloc(char *file);

#endif /* !BSQ_H_ */
