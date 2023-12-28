/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dub_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:30:29 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:06 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_dub_char(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'E')
	{
		map->check_e++;
		if (map->check_e != 1)
			print_error("double E");
	}
	if (line[i] == 'F')
	{
		map->check_f++;
		if (map->check_f != 1)
			print_error("double F");
	}
	if (line[i] == 'C')
	{
		map->check_c++;
		if (map->check_c != 1)
			print_error("double C");
	}
}

void	check_double_char(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N')
	{
		map->check_n++;
		if (map->check_n != 1)
			print_error("double N");
	}
	if (line[i] == 'S')
	{
		map->check_s++;
		if (map->check_s != 1)
			print_error("double S");
	}
	if (line[i] == 'W')
	{
		map->check_w++;
		if (map->check_w != 1)
			print_error("double W");
	}
}

void	function_initialisation(t_map *map)
{
	map->check_n = 0;
	map->check_s = 0;
	map->check_w = 0;
	map->check_e = 0;
	map->check_f = 0;
	map->check_c = 0;
	map->fc->floor = NULL;
	map->fc->ceiling = NULL;
	map->fc->floor_rgb->r = 0;
	map->fc->floor_rgb->g = 0;
	map->fc->floor_rgb->b = 0;
	map->fc->ceiling_rgb->r = 0;
	map->fc->ceiling_rgb->g = 0;
	map->fc->ceiling_rgb->b = 0;
}
