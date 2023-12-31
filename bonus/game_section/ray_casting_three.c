/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:38:02 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/31 10:57:44 by oait-bad         ###   ########.fr       */
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
					/ data->tile_size) - 1] == '1'
				|| data->map_tot[(int)(*nexttouchvert_y
					/ data->tile_size)][(int)(*nexttouchvert_x
					/ data->tile_size) - 1] == ' ')
			{
				vert_wall_hit(data, nexttouchvert_x, nexttouchvert_y);
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
				vert_wall_hit(data, nexttouchvert_x, nexttouchvert_y);
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
				- 1][(int)(*nexttouchhorz_x / data->tile_size)] == '1'
				|| data->map_tot[(int)(*nexttouchhorz_y / data->tile_size)
				- 1][(int)(*nexttouchhorz_x / data->tile_size)] == ' ')
			{
				horz_wall_hit(data, nexttouchhorz_x, nexttouchhorz_y);
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
				horz_wall_hit(data, nexttouchhorz_x, nexttouchhorz_y);
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
