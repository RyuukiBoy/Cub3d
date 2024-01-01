/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:09:20 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/01 17:48:36 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_i(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map_tot[i])
	{
		j = 0;
		while (map->map_tot[i][j] == ' ' || map->map_tot[i][j] == '\t')
			j++;
		if (map->map_tot[i][j] != '1' && map->map_tot[i][j] == '\n')
		{
			print_error("ERROR : i -- map must be closed by walls ! \n", map);
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map_tot[i] && j < ft_strlen(map->map_tot[0]))
	{
		if (map->map_tot[i][j] != '1' && map->map_tot[i][j] != ' '
			&& map->map_tot[i][j] != '\n')
		{
			print_error("ERROR :j -- la carte n'est pas entouree par des murs!",
				map);
		}
		j++;
	}
	check_i(map);
	check_len_i(map);
	check_len_j(map);
}

size_t	ft_strleen(char **ptr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (ptr[i][j])
	{
		j++;
	}
	return (j);
}

size_t	ft_strlenn(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i++;
	}
	return (i);
}
