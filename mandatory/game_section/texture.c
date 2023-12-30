/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:34:37 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 19:24:52 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_close(t_map *map)
{
	close(map->textures->ea);
	close(map->textures->no);
	close(map->textures->so);
	close(map->textures->we);
}

void	check_color_err(t_map *map)
{
	if (map->fc->ceiling == NULL || map->fc->floor == NULL)
		print_error("ERROR : map without f_floor / c_ceiling");
}

void	valid_path_texture(t_map *map)
{
	map->posi_ea += 3;
	map->textures->ea = open(map->posi_ea, O_RDONLY);
	if (map->textures->ea < 0)
		print_error("Error : ea invalid texture path \n");
	map->posi_no += 3;
	map->textures->no = open(map->posi_no, O_RDONLY);
	if (map->textures->no < 0)
		print_error("Error : no invalid texture path \n");
	map->posi_so += 3;
	map->textures->so = open(map->posi_so, O_RDONLY);
	if (map->textures->so < 0)
		print_error("Error : so invalid texture path \n");
	map->posi_we += 3;
	map->textures->we = open(map->posi_we, O_RDONLY);
	if (map->textures->we < 0)
		print_error("Error : we invalid texture path \n");
	ft_close(map);
}

void	check_texture(t_map *map)
{
	if (map->posi_no == NULL || map->posi_so == NULL || map->posi_we == NULL
		|| map->posi_ea == NULL)
		print_error("error : error_texture\n");
	if (ft_strncmp(map->posi_so + ft_strlen(map->posi_so) - 4, ".xpm", 4) != 0)
		print_error("Error: a texture extension file\n");
	if (ft_strncmp(map->posi_no + ft_strlen(map->posi_no) - 4, ".xpm", 4) != 0)
		print_error("Error: b  texture extension file\n");
	if (ft_strncmp(map->posi_ea + ft_strlen(map->posi_ea) - 4, ".xpm", 4) != 0)
		print_error("Error: c  texture extension file\n");
	if (ft_strncmp(map->posi_we + ft_strlen(map->posi_we) - 4, ".xpm", 4) != 0)
		print_error("Error: d  texture extension file\n");
	valid_path_texture(map);
}
