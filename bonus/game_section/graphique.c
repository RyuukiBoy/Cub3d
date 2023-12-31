/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:13:38 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/31 10:12:14 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	new_initialisation(t_map *data)
{
	data->x_intercept = 0;
	data->y_intercept = 0;
	data->x_ver_intercept = 0;
	data->y_ver_intercept = 0;
	data->was_hit_horizontal = 0;
	data->was_hit_vertical = 0;
	data->x_ver_step = 0;
	data->y_ver_step = 0;
	data->vert_x = 0;
	data->vert_y = 0;
	data->wall_vert_x = 0;
	data->wall_vert_y = 0;
	data->x_dest = 0;
	data->y_dest = 0;
	data->horz_distance = 0;
	data->vert_distance = 0;
	data->distance = 0;
}

void	init_data(t_map *data)
{
	data->x = 0;
	data->y = 0;
	data->tile_size = 70;
	data->win_width = data->len_max * data->tile_size;
	data->win_height = data->map_rows * data->tile_size;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "cub3d");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->x = data->win_width / 2;
	data->y = data->win_height / 2;
	data->radius = 5;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->strafe_direction = 0;
	data->rotation_angle = 3 * (M_PI / 2);
	data->move_speed = 0.12;
	data->rotation_speed = 2 * (M_PI / 180);
	data->num_rays = data->win_width / 5;
	data->distance = 0;
	data->fov = 60 * (M_PI / 180);
	new_initialisation(data);
}

void	select_player_direction(t_map *data, char c)
{
	if (c == 'N')
		data->rotation_angle = 3 * (M_PI / 2);
	else if (c == 'S')
		data->rotation_angle = M_PI / 2;
	else if (c == 'E')
		data->rotation_angle = 0;
	else if (c == 'W')
		data->rotation_angle = M_PI;
}

void	get_player_pos(t_map *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map_rows)
	{
		j = 0;
		while (j < data->len_nor)
		{
			if (data->map_tot[i][j] == 'N' || data->map_tot[i][j] == 'S'
				|| data->map_tot[i][j] == 'E' || data->map_tot[i][j] == 'W')
			{
				select_player_direction(data, data->map_tot[i][j]);
				data->p_x = j;
				data->p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
