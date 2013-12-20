##
## Makefile for bsq in /home/chapui_s/travaux/bsq/bsq_malloc
## 
## Made by chapui_s
## Login   <chapui_s@epitech.net>
## 
## Started on  Wed Dec  4 22:12:59 2013 chapui_s
## Last update Sun Dec  8 18:42:04 2013 chapui_s
##

SRC	= bsq.c \
	  arg.c \
	  check.c \
	  disp_bsq.c \
	  errors.c \
	  get_lc.c \
	  my_atoi.c \
	  gere_malloc.c \
	  utils2.c \
	  utils.c \
	  put_error_out.c \
	  gen_map.c

NAME	= bsq

CFLAGS	= -O3

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) $(CFLAGS)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
