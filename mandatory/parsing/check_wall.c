/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:18:12 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/04 11:16:35 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_len_i(t_map *map)
{
	size_t	j;
	size_t	len_j;
	size_t	len_i;

	j = 0;
	len_j = ft_strleen(map->map_tot);
	len_i = ft_strlenn(map->map_tot);
	while (j < len_j)
	{
		if (map->map_tot[len_i - 1][j] != '1' && map->map_tot[len_i
			- 1][j] != ' ')
		{
			print_error("ERROR :len_i --- map must be closed by walls ! \n",
				map);
		}
		j++;
	}
}

void	check_len_j(t_map *map)
{
	size_t	i;
	size_t	len_j;
	size_t	len_i;

	i = 0;
	len_j = ft_strleen(map->map_tot) - 1;
	len_i = ft_strlenn(map->map_tot) - 1;
	while (i < len_i)
	{
		len_j = ft_strleen(map->map_tot) - 1;
		while (len_j && (map->map_tot[i][len_j] == ' '
			|| map->map_tot[i][len_j] == '\t'))
		{
			len_j--;
		}
		if (map->map_tot[i][len_j] != '1')
		{
			print_error("ERROR :len_j --- map must be closed by walls ! \n",
				map);
		}
		i++;
	}
}
