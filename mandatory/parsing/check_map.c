/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:48:39 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:25 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_player_second(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tot[i])
	{
		j = 0;
		while (map->map_tot[i][j])
		{
			if (map->map_tot[i][j] == 'N' || map->map_tot[i][j] == 'E'
				|| map->map_tot[i][j] == 'W' || map->map_tot[i][j] == 'S')
			{
				if (map->map_tot[i][j + 1] == '1' && map->map_tot[i][j
					- 1] == '1' && map->map_tot[i + 1][j] == '1'
					&& map->map_tot[i + 1][j] == '1')
					print_error("Error : player entourer des murs");
			}
			j++;
		}
		i++;
	}
}

void	check_player(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map->map_tot[i])
	{
		j = 0;
		while (map->map_tot[i][j])
		{
			if (map->map_tot[i][j] == 'N' || map->map_tot[i][j] == 'E'
				|| map->map_tot[i][j] == 'W' || map->map_tot[i][j] == 'S')
			{
				k++;
			}
			j++;
		}
		i++;
	}
	if (k > 1 || k == 0)
		error_print("ERROR : the player position ! \n");
	check_player_second(map);
}

void	check_allmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tot[i])
	{
		j = 0;
		while (map->map_tot[i][j])
		{
			if (map->map_tot[i][j] != '1' && map->map_tot[i][j] != '0'
				&& map->map_tot[i][j] != 'E' && map->map_tot[i][j] != 'S'
				&& map->map_tot[i][j] != 'N' && map->map_tot[i][j] != 'W'
				&& map->map_tot[i][j] != ' ' && map->map_tot[i][j] != '\t')
			{
				printf("ERROR : map should have just 6 elements \n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	int	i;

	i = 0;
	map->ptr = ft_strtrim_to_free(map->ptr, "\n");
	while (map->ptr[i])
	{
		if (map->ptr[i] == '\n' && map->ptr[i + 1] == '\n')
			print_error("nex_line in map");
		i++;
	}
	if (map->ptr)
		map->map_tot = ft_split(map->ptr, '\n');
	if (map->map_tot[0] == NULL)
		print_error("Error : no map in the file");
	i = 0;
	while (map->map_tot[i])
	{
		if (map->map_tot[i + 1] == NULL)
			map->var4 = 1;
		i++;
	}
	map->map_rows = ft_strlenn(map->map_tot);
	check_map_length(map);
	check_walls(map);
	check_allmap(map);
}