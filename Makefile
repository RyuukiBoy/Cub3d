NAME= cub3D
CC= cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3

SRC= cub3d.c utils.c colors_buffer.c moves.c raycasting.c engine_calculation.c wall_projection.c draw_map.c gnl/gnl_u.c gnl/gnl.c 
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all