/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:37:24 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/01 17:48:16 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	function_norm(t_map *map, int i, int j)
{
	if (map->map_tot[i + 1] && map->map_tot[i + 1][j] != ' ' && map->map_tot[i
		+ 1][j] != '1')
		print_error("ERROR : spaces \n", map);
	if (i > 0 && map->map_tot[i - 1] && map->map_tot[i - 1] && map->map_tot[i
			- 1][j] != ' ' && map->map_tot[i - 1][j] != '1')
		print_error("ERROR : spaces \n", map);
}

void	check_space_errors(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map_tot[i])
	{
		j = 0;
		while (map->map_tot[i][j])
		{
			if (map->map_tot[i][j] == ' ')
			{
				if (map->map_tot[i][j + 1] && map->map_tot[i][j + 1] != ' '
					&& map->map_tot[i][j + 1] != '1')
					print_error("ERROR : spaces \n", map);
				if (j > 0 && map->map_tot[i][j - 1] && map->map_tot[i][j
					- 1] != ' ' && map->map_tot[i][j - 1] != '1')
					print_error("ERROR : spaces \n", map);
				function_norm(map, i, j);
			}
			j++;
		}
		i++;
	}
}

char	*skip_space(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}
