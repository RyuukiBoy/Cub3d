/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:18 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/31 10:11:22 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	len_max(t_map *map)
{
	int	i;
	int	len_max;
	int	c_len;

	map->len_max = 0;
	i = 0;
	len_max = 0;
	c_len = 0;
	while (map->map_tot[i])
	{
		c_len = ft_strlen(map->map_tot[i]);
		if (c_len > len_max)
		{
			len_max = c_len;
		}
		i++;
	}
	map->len_max = len_max;
	return (len_max);
}

void	check_map_length(t_map *map)
{
	map->k_nor = 0;
	map->len_nor = len_max(map);
	while (map->map_tot[map->k_nor])
	{
		map->c_len_nor = ft_strlen(map->map_tot[map->k_nor]);
		if (map->c_len_nor < map->len_nor)
		{
			map->new_line = (char *)malloc(map->len_nor + 1);
			if (map->new_line)
			{
				ft_strttcpy(map->new_line, map->map_tot[map->k_nor]);
				map->j_nor = map->c_len_nor;
				while (map->j_nor < map->len_nor)
				{
					map->new_line[map->j_nor] = ' ';
					map->j_nor++;
				}
				map->new_line[map->len_nor] = '\0';
				free(map->map_tot[map->k_nor]);
				map->map_tot[map->k_nor] = map->new_line;
			}
		}
		map->k_nor++;
	}
}

void	func_initial(t_map *map)
{
	map->len_nor = 0;
	map->map_rows = 0;
	map->var1 = 0;
	map->var2 = 0;
	map->var3 = 0;
	map->var4 = 0;
	map->posi_no = NULL;
	map->posi_so = NULL;
	map->posi_ea = NULL;
	map->posi_we = NULL;
	map->len_col = 0;
	map->map_tot = NULL;
	map->ptr = NULL;
	map->col_c = NULL;
	map->col_f = NULL;
	map->len = 0;
	map->h = 0;
	function_initialisation(map);
}

void	exit_fail(void)
{
	printf("error\n");
	exit(1);
}

void	print_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}
