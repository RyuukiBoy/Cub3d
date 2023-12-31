/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:37:24 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/30 18:57:50 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	function_norm(t_map *map, int i, int j)
{
	if (map->map_tot[i + 1] && map->map_tot[i + 1][j] != ' ' && map->map_tot[i
		+ 1][j] != '1')
		error_print("ERROR : spaces \n");
	if (i > 0 && map->map_tot[i - 1] && map->map_tot[i - 1] && map->map_tot[i
			- 1][j] != ' ' && map->map_tot[i - 1][j] != '1')
		error_print("ERROR : spaces \n");
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
					error_print("ERROR : spaces \n");
				if (j > 0 && map->map_tot[i][j - 1] && map->map_tot[i][j
					- 1] != ' ' && map->map_tot[i][j - 1] != '1')
					error_print("ERROR : spaces \n");
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
