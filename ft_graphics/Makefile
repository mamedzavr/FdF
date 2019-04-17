NAME = libftgraphics.a
SRCS = ./srcs/window.c ./srcs/convertcolor.c ./srcs/put_pixel_to_image.c ./srcs/image.c ./srcs/multpoint.c ./srcs/rotate.c ./srcs/createpoint.c ./srcs/createrect.c ./srcs/setpoint1.c ./srcs/setpoint2.c ./srcs/setrect.c ./srcs/minuspoint.c ./srcs/plusepoint.c ./srcs/ft_lerp.c ./srcs/createcolor.c ./srcs/setcolor.c ./srcs/drawline.c ./srcs/drawrect.c ./srcs/collision.c
INCLUDES = ./includes/

MLXINCLUDE = -I /usr/local/include

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror $(SRCS) $(MLXINCLUDE) -I $(INCLUDES) -c
	ar rc $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
