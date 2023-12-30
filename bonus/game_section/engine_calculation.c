/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:12 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/28 18:59:08 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_directions(t_map *data, float ray_angle)
{
	data->is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	data->is_ray_facing_up = !data->is_ray_facing_down;
	data->is_ray_facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5
		* M_PI;
	data->is_ray_facing_left = !data->is_ray_facing_right;
}

void	horz_intercepts(t_map *data, float *nexttouchhorz_x,
		float *nexttouchhorz_y)
{
	float	x_intercept;
	float	y_intercept;
	float	x;
	float	y;

	x = data->p_x * data->tile_size + data->tile_size / 2;
	y = data->p_y * data->tile_size + data->tile_size / 2;
	y_intercept = floor(y / data->tile_size) * data->tile_size;
	if (data->is_ray_facing_down)
		y_intercept += data->tile_size;
	x_intercept = x + (y_intercept - y) / tan(data->ray_angle);
	data->y_step = data->tile_size;
	if (!data->is_ray_facing_down)
		data->y_step *= -1;
	data->x_step = data->tile_size / tan(data->ray_angle);
	if (data->is_ray_facing_left && data->x_step > 0)
		data->x_step *= -1;
	if (data->is_ray_facing_right && data->x_step < 0)
		data->x_step *= -1;
	*nexttouchhorz_x = x_intercept;
	*nexttouchhorz_y = y_intercept;
}

void	vert_intercepts(t_map *data, float *nexttouchvert_x,
		float *nexttouchvert_y)
{
	float	x_intercept;
	float	y_intercept;
	float	x;
	float	y;

	x = data->p_x * data->tile_size + data->tile_size / 2;
	y = data->p_y * data->tile_size + data->tile_size / 2;
	x_intercept = floor(x / data->tile_size) * data->tile_size;
	if (data->is_ray_facing_right)
		x_intercept += data->tile_size;
	y_intercept = y + (x_intercept - x) * tan(data->ray_angle);
	data->x_ver_step = data->tile_size;
	if (!data->is_ray_facing_right)
		data->x_ver_step *= -1;
	data->y_ver_step = data->tile_size * tan(data->ray_angle);
	if (data->is_ray_facing_up && data->y_ver_step > 0)
		data->y_ver_step *= -1;
	if (data->is_ray_facing_down && data->y_ver_step < 0)
		data->y_ver_step *= -1;
	*nexttouchvert_x = x_intercept;
	*nexttouchvert_y = y_intercept;
}
