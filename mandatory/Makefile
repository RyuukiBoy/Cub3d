# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:23 by ybouzafo          #+#    #+#              #
#    Updated: 2024/01/01 16:51:41 by ybouzafo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cub3D

CC= cc
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address -g3

RM=rm -f
SRC =  game_section/wall_projection.c parsing/cub.c parsing/get_line.c libft/ft_split.c libft/ft_strdup.c libft/ft_atoi.c  libft/ft_substr.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strtrim.c libft/ft_strchr.c \
		parsing/ft_strncmp.c game_section/utils.c parsing/check_map.c parsing/check_walls.c parsing/cub_deux.c parsing/check_wall.c parsing/check_m.c game_section/texture.c parsing/check_dub_char.c parsing/check_ma.c libft/ft_strlcpy.c parsing/check_space.c game_section/main.c game_section/mlx.c game_section/graphique.c game_section/move_player.c game_section/drawing.c game_section/ray_casting.c game_section/engine_calculation.c\
		game_section/ray_casting_two.c game_section/ray_casting_three.c game_section/utils_2.c game_section/utils_norm.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all
