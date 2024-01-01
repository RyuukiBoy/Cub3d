/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:38 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/01 17:52:28 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	stock_f_color(t_map *map, char **ptr)
{
	if (ptr[0] == NULL || ptr[1] == NULL || ptr[2] == NULL)
		print_error("ERROR : color : pas de couleur", map);
	map->fc->floor_rgb->r = ft_atoi(ptr[0]);
	map->fc->floor_rgb->g = ft_atoi(ptr[1]);
	map->fc->floor_rgb->b = ft_atoi(ptr[2]);
}

int	check_err_col_f(char *line, t_map *map)
{
	int		i;
	char	**ptr;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(skip_tab_space(line + 1), "\n");
	check_virg(tmp, map);
	ptr = ft_split(tmp, ',');
	while (ptr[i])
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0
			|| !ft_is_digit(*ptr[i]))
			print_error("f/c_error color \n", map);
		i++;
	}
	stock_f_color(map, ptr);
	free(tmp);
	ft_free(ptr);
	map->var3 = 1;
	return (1);
}

void	stock_c_color(t_map *map, char **ptr)
{
	if (ptr[0] == NULL || ptr[1] == NULL || ptr[2] == NULL)
		print_error("ERROR : color : pas de couleur", map);
	map->fc->ceiling_rgb->r = ft_atoi(ptr[0]);
	map->fc->ceiling_rgb->g = ft_atoi(ptr[1]);
	map->fc->ceiling_rgb->b = ft_atoi(ptr[2]);
}

int	check_err_col_c(char *line, t_map *map)
{
	int		i;
	char	**ptr;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(skip_tab_space(line + 1), "\n");
	check_virg(tmp, map);
	ptr = ft_split(tmp, ',');
	while (ptr[i])
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0)
		{
			print_error("f/c_error color \n", map);
		}
		i++;
	}
	stock_c_color(map, ptr);
	free(tmp);
	ft_free(ptr);
	map->var3 = 1;
	return (1);
}
