/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:38:06 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/28 19:21:02 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	get_ray_angle(t_map *data)
{
	float	ray_angle;

	ray_angle = data->rotation_angle - (data->fov / 2);
	if (ray_angle < 0)
		ray_angle += 2 * M_PI;
	if (ray_angle > 2 * M_PI)
		ray_angle -= 2 * M_PI;
	return (ray_angle);
}

void	vert_cast(t_map *data)
{
	float	nexttouchvert_x;
	float	nexttouchvert_y;

	data->found_vert_wall_hit = 0;
	vert_intercepts(data, &nexttouchvert_x, &nexttouchvert_y);
	vert_cast_1(data, &nexttouchvert_x, &nexttouchvert_y);
	vert_cast_2(data, &nexttouchvert_x, &nexttouchvert_y);
}

void	dis_for_norm(t_map *data, float *horz_distance, float *vert_distance)
{
	if (*vert_distance < *horz_distance)
	{
		data->distance = *vert_distance;
		data->x_dest = data->wall_vert_x;
		data->y_dest = data->wall_vert_y;
		data->wall_hit_content = data->vert_content;
		data->was_hit_vertical = 1;
		data->was_hit_horizontal = 0;
	}
	else
	{
		data->distance = *horz_distance;
		data->x_dest = data->wall_hit_x;
		data->y_dest = data->wall_hit_y;
		data->wall_hit_content = data->horz_content;
		data->was_hit_horizontal = 1;
		data->was_hit_vertical = 0;
	}
}

void	ray_facing_checker(t_map *data, float *horz_distance,
		float *vert_distance)
{
	float	x;
	float	y;

	x = data->p_x * data->tile_size + data->tile_size / 2;
	y = data->p_y * data->tile_size + data->tile_size / 2;
	if (data->found_horz_wall_hit)
		*horz_distance = distance_bt_points(x, y, data->wall_hit_x,
				data->wall_hit_y);
	else
		*horz_distance = INT_MAX;
	if (data->found_vert_wall_hit)
		*vert_distance = distance_bt_points(x, y, data->wall_vert_x,
				data->wall_vert_y);
	else
		*vert_distance = INT_MAX;
	dis_for_norm(data, horz_distance, vert_distance);
}

void	raycasting(t_map *data)
{
	float	horz_distance;
	float	vert_distance;

	data->ray_angle = normalize_angle(data->ray_angle);
	init_directions(data, data->ray_angle);
	horz_cast(data);
	vert_cast(data);
	ray_facing_checker(data, &horz_distance, &vert_distance);
}
