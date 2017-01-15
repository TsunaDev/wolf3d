##
## Makefile for wolf3D in /home/tsuna/Epitech/projects/Infograph/wolf3d/wolf/wolf3d
## 
## Made by Martin Van Elslande
## Login   <martin.van-elslande@epitech.eu>
## 
## Started on  Fri Dec 23 14:25:40 2016 Martin Van Elslande
## Last update Sun Jan 15 22:30:26 2017 Martin Van Elslande
##

CFLAGS	=	-Iinclude -Wall -Wextra

SRC	=	src/main.c		\
		src/raycast.c		\
		src/move_forward.c	\
		src/my_draw_line.c	\
		src/my_put_pixel.c	\
		src/match.c		\
		src/errors.c		\
		src/wolf3d.c		\
		src/window.c		\
		src/pos.c		\
		src/usable_raycast.c	\
		src/music.c		\
		src/chicken.c		\
		src/my_utils.c		\
		src/help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

all:	$(NAME)

debug:	CFLAGS += -ggdb3

debug:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
