# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:01:23 by ybouzafo          #+#    #+#              #
#    Updated: 2023/12/30 18:19:53 by oait-bad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= cub3D
NAME_BONUS= cub3D_bonus

CC= cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3

RM=rm -f
SRC =  mandatory/game_section/wall_projection.c mandatory/parsing/cub.c mandatory/parsing/get_line.c mandatory/libft/ft_split.c mandatory/libft/ft_strdup.c mandatory/libft/ft_atoi.c  mandatory/libft/ft_substr.c mandatory/libft/ft_strjoin.c mandatory/libft/ft_strlen.c mandatory/libft/ft_strtrim.c mandatory/libft/ft_strchr.c \
		mandatory/parsing/ft_strncmp.c mandatory/game_section/utils.c mandatory/parsing/check_map.c mandatory/parsing/check_walls.c mandatory/parsing/cub_deux.c mandatory/parsing/check_wall.c mandatory/parsing/check_m.c mandatory/game_section/texture.c mandatory/parsing/check_dub_char.c mandatory/parsing/check_ma.c mandatory/libft/ft_strlcpy.c mandatory/parsing/check_space.c mandatory/game_section/main.c mandatory/game_section/mlx.c mandatory/game_section/graphique.c mandatory/game_section/move_player.c mandatory/game_section/drawing.c mandatory/game_section/ray_casting.c mandatory/game_section/engine_calculation.c\
		mandatory/game_section/ray_casting_two.c mandatory/game_section/ray_casting_three.c mandatory/game_section/utils_2.c\

OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/game_section/wall_projection.c bonus/parsing/cub.c bonus/parsing/get_line.c bonus/libft/ft_split.c bonus/libft/ft_strdup.c bonus/libft/ft_atoi.c  bonus/libft/ft_substr.c bonus/libft/ft_strjoin.c bonus/libft/ft_strlen.c bonus/libft/ft_strtrim.c bonus/libft/ft_strchr.c \
		bonus/parsing/ft_strncmp.c bonus/game_section/utils.c bonus/parsing/check_map.c bonus/parsing/check_walls.c bonus/parsing/cub_deux.c bonus/parsing/check_wall.c bonus/parsing/check_m.c bonus/game_section/texture.c bonus/parsing/check_dub_char.c bonus/parsing/check_ma.c bonus/libft/ft_strlcpy.c bonus/parsing/check_space.c bonus/game_section/main.c bonus/game_section/mlx.c bonus/game_section/graphique.c bonus/game_section/move_player.c bonus/game_section/drawing.c bonus/game_section/ray_casting.c bonus/game_section/engine_calculation.c\
		bonus/game_section/ray_casting_two.c bonus/game_section/ray_casting_three.c bonus/game_section/utils_2.c bonus/game_section/mouse_move.c\

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)
fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
