/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:38:02 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/31 08:39:37 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	vert_cast_2(t_map *data, float *nexttouchvert_x, float *nexttouchvert_y)
{
	if (data->is_ray_facing_left)
	{
		while (*nexttouchvert_y >= 0 && *nexttouchvert_x >= 0
			&& *nexttouchvert_y < data->win_height
			&& *nexttouchvert_x < data->win_width)
		{
			if (data->map_tot[(int)(*nexttouchvert_y
					/ data->tile_size)][(int)(*nexttouchvert_x
					/ data->tile_size) - 1] == '1' || data->map_tot[(int)(*nexttouchvert_y
					/ data->tile_size)][(int)(*nexttouchvert_x
					/ data->tile_size) - 1] == ' ')
			{
				data->found_vert_wall_hit = 1;
				data->wall_vert_x = *nexttouchvert_x;
				data->wall_vert_y = *nexttouchvert_y;
				data->vert_content = data->map_tot[(int)(*nexttouchvert_y
						/ data->tile_size)][(int)(*nexttouchvert_x
						/ data->tile_size) - 1];
				break ;
			}
			else
			{
				*nexttouchvert_x += data->x_ver_step;
				*nexttouchvert_y += data->y_ver_step;
			}
		}
	}
}

void	vert_cast_1(t_map *data, float *nexttouchvert_x, float *nexttouchvert_y)
{
	if (data->is_ray_facing_right)
	{
		while (*nexttouchvert_y >= 0 && *nexttouchvert_x >= 0
			&& *nexttouchvert_y < data->win_height
			&& *nexttouchvert_x < data->win_width)
		{
			if (data->map_tot[(int)(*nexttouchvert_y
					/ data->tile_size)][(int)(*nexttouchvert_x
					/ data->tile_size)] == '1')
			{
				data->found_vert_wall_hit = 1;
				data->wall_vert_x = *nexttouchvert_x;
				data->wall_vert_y = *nexttouchvert_y;
				data->vert_content = data->map_tot[(int)(*nexttouchvert_y
						/ data->tile_size)][(int)(*nexttouchvert_x
						/ data->tile_size)];
				break ;
			}
			else
			{
				*nexttouchvert_x += data->x_ver_step;
				*nexttouchvert_y += data->y_ver_step;
			}
		}
	}
}

void	horz_cast(t_map *data)
{
	float	nexttouchhorz_x;
	float	nexttouchhorz_y;

	data->found_horz_wall_hit = 0;
	horz_intercepts(data, &nexttouchhorz_x, &nexttouchhorz_y);
	horz_cast_1(data, &nexttouchhorz_x, &nexttouchhorz_y);
	horz_cast_2(data, &nexttouchhorz_x, &nexttouchhorz_y);
}

void	horz_cast_2(t_map *data, float *nexttouchhorz_x, float *nexttouchhorz_y)
{
	if (data->is_ray_facing_up)
	{
		while (*nexttouchhorz_y >= 0 && *nexttouchhorz_x >= 0
			&& *nexttouchhorz_y < data->win_height
			&& *nexttouchhorz_x < data->win_width)
		{
			if (data->map_tot[(int)(*nexttouchhorz_y / data->tile_size)
				- 1][(int)(*nexttouchhorz_x / data->tile_size)] == '1' || data->map_tot[(int)(*nexttouchhorz_y / data->tile_size)
				- 1][(int)(*nexttouchhorz_x / data->tile_size)] == ' ')
			{
				data->found_horz_wall_hit = 1;
				data->wall_hit_x = *nexttouchhorz_x;
				data->wall_hit_y = *nexttouchhorz_y;
				data->horz_content = data->map_tot[(int)(*nexttouchhorz_y
						/ data->tile_size) - 1][(int)(*nexttouchhorz_x
						/ data->tile_size)];
				break ;
			}
			else
			{
				*nexttouchhorz_x += data->x_step;
				*nexttouchhorz_y += data->y_step;
			}
		}
	}
}

void	horz_cast_1(t_map *data, float *nexttouchhorz_x, float *nexttouchhorz_y)
{
	if (data->is_ray_facing_down)
	{
		while (*nexttouchhorz_y >= 0 && *nexttouchhorz_x >= 0
			&& *nexttouchhorz_y < data->win_height
			&& *nexttouchhorz_x < data->win_width)
		{
			if (data->map_tot[(int)(*nexttouchhorz_y
					/ data->tile_size)][(int)(*nexttouchhorz_x
					/ data->tile_size)] == '1')
			{
				data->found_horz_wall_hit = 1;
				data->wall_hit_x = *nexttouchhorz_x;
				data->wall_hit_y = *nexttouchhorz_y;
				data->horz_content = data->map_tot[(int)(*nexttouchhorz_y
						/ data->tile_size)][(int)(*nexttouchhorz_x
						/ data->tile_size)];
				break ;
			}
			else
			{
				*nexttouchhorz_x += data->x_step;
				*nexttouchhorz_y += data->y_step;
			}
		}
	}
}
