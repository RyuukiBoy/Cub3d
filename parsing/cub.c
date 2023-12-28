/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:14 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:47 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_norm_deux(char *line, t_map *map)
{
	if (ft_strncmp(skip_space(line), "EA ", 3) == 0)
	{
		line = ft_strtrim(line, "\n");
		map->posi_ea = malloc(ft_strlen(line) + 1);
		ft_strcopy(map->posi_ea, line);
		free(line);
		return (1);
	}
	else if (ft_strncmp(skip_space(line), "WE ", 3) == 0)
	{
		line = ft_strtrim(line, "\n");
		map->posi_we = malloc(ft_strlen(line) + 1);
		ft_strcopy(map->posi_we, line);
		free(line);
		return (1);
	}
	return (0);
}

int	check_norm(char *line, t_map *map)
{
	if (ft_strncmp(skip_space(line), "F ", 2) == 0)
	{
		if (check_err_col_f(skip_space(line), map) != 0)
		{
			map->fc->floor = malloc(ft_strlen(line) + 1);
			ft_strcopy(map->fc->floor, line);
			map->fc->fl = create_rgb(map->fc->floor_rgb->r,
					map->fc->floor_rgb->g, map->fc->floor_rgb->b);
			return (1);
		}
	}
	else if (ft_strncmp(skip_space(line), "C ", 2) == 0)
	{
		if (check_err_col_c(skip_space(line), map) != 0)
		{
			map->fc->ceiling = malloc(ft_strlen(line) + 1);
			ft_strcopy(map->fc->ceiling, line);
			map->fc->ce = create_rgb(map->fc->ceiling_rgb->r,
					map->fc->ceiling_rgb->g, map->fc->ceiling_rgb->b);
			return (1);
		}
	}
	return (0);
}

int	check_position(char *line, t_map *map)
{
	if (line[0] == '\n')
		return (0);
	else if ((ft_strncmp(skip_space(line), "NO ", 3)) == 0)
	{
		line = ft_strtrim(line, "\n");
		map->posi_no = malloc(ft_strlen(line) + 1);
		ft_strcopy(map->posi_no, line);
		free(line);
		return (1);
	}
	else if (ft_strncmp(skip_space(line), "SO ", 3) == 0)
	{
		line = ft_strtrim(line, "\n");
		map->posi_so = malloc(ft_strlen(line) + 1);
		ft_strcopy(map->posi_so, line);
		free(line);
		return (1);
	}
	if (check_norm(line, map) == 1)
		return (1);
	if (check_norm_deux(line, map) == 1)
		return (1);
	else
		return (0);
	return (18);
}

void	first(char *line, t_map *map, char *tmp)
{
	if (line[0] == '\n' || check_line_one(line) == 1
		|| check_line_one(line) == 2)
	{
		if (check_line_one(line) == 1 && check_position(line, map) == 1)
			map->var1 = 1;
		else if (check_line_one(skip_space(line)) == 5
			|| (check_line_one(line) == 2 && map->var1 == 1
				&& first_map(line) == 1 && map->var3 == 1))
		{
			map->var2 = 1;
			tmp = ft_strjoin(map->ptr, line);
			if (map->ptr != NULL)
				free(map->ptr);
			map->ptr = tmp;
		}
		else if (line[0] == '\n' && map->var2 == 1 && map->var4 == 1)
			print_error("Error : invalid map \n");
		else if (check_position(skip_space(line), map) == 0)
			print_error(" b : Error : map invalid \n");
	}
	else if (check_line_one(line) == -1)
		print_error("c : error invalid map \n");
}
