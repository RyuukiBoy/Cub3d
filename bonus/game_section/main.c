/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:36:14 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/01 17:55:17 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	exit_fail(int fd, t_map *map)
{
	(void)map;
	printf("Error : open file \n");
	close(fd);
	exit(1);
}

void	get_map(t_map *map, char **av)
{
	int		fd;
	char	*line;

	func_initial(map);
	fd = open(av[1], O_RDWR);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0 || fd < 0)
		exit_fail(fd, map);
	line = get_next_line(fd);
	if (!line)
		print_error("empty file \n", map);
	while (line != 0)
	{
		check_double_char(line, map);
		check_dub_char(line, map);
		first(line, map, NULL);
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	check_map(map);
	check_player(map);
	check_space_errors(map);
	check_texture(map);
	check_color_err(map);
}

int	main(int ac, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->textures = malloc(sizeof(t_textures));
	map->fc = malloc(sizeof(t_fc));
	map->fc->floor_rgb = malloc(sizeof(t_rgb));
	map->fc->ceiling_rgb = malloc(sizeof(t_rgb));
	if (!map)
		return (0);
	if (ac == 2)
	{
		get_map(map, argv);
		init_data(map);
		init_img(map);
		get_player_pos(map);
		mlx_hook(map->win_ptr, 2, 1L << 0, key_press, map);
		mlx_hook(map->win_ptr, 3, 1L << 1, key_release, map);
		mlx_hook(map->win_ptr, 17, 0, &ft_exit, NULL);
		mlx_loop_hook(map->mlx_ptr, update, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		printf("error args \n");
	fonction_to_free(map);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
