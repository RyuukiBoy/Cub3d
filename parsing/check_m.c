/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:38 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:18 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error_print(char *str)
{
	printf("%s", str);
	exit(1);
}

void	stock_f_color(t_map *map, char **ptr)
{
	if (ptr[0] == NULL || ptr[1] == NULL || ptr[2] == NULL)
		print_error("ERROR : color : pas de couleur");
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
	tmp = ft_strtrim(line + 2, "\n");
	ptr = ft_split(tmp, ',');
	while (ptr[i])
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0
			|| !ft_is_digit(*ptr[i]))
		{
			printf("f/c_error color \n");
			exit(1);
		}
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
		print_error("ERROR : color : pas de couleur");
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
	tmp = ft_strtrim(line + 2, "\n");
	ptr = ft_split(tmp, ',');
	while (ptr[i])
	{
		if (ft_atoi(ptr[i]) > 255 || ft_atoi(ptr[i]) < 0)
		{
			printf("f/c_error color \n");
			exit(1);
		}
		i++;
	}
	stock_c_color(map, ptr);
	free(tmp);
	ft_free(ptr);
	map->var3 = 1;
	return (1);
}
