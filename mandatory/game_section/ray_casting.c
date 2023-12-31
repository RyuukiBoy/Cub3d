/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:34:36 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/31 08:12:26 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	casting(t_map *data, t_utils *utils)
{
	if (utils->y > data->y_dest)
	{
		while (utils->x > data->x_dest && utils->y > data->y_dest
			&& utils->x > 0 && utils->y > 0)
		{
			my_mlx_pixel_put(data, utils->x, utils->y, 0x000000FF);
			utils->x += utils->dx;
			utils->y += utils->dy;
		}
	}
	else
	{
		while (utils->x > data->x_dest && utils->y < data->y_dest
			&& utils->x > 0 && utils->y > 0)
		{
			my_mlx_pixel_put(data, utils->x, utils->y, 0x000000FF);
			utils->x += utils->dx;
			utils->y += utils->dy;
		}
	}
}

void	casting_again(t_map *data, t_utils *utils)
{
	if (utils->y > data->y_dest)
	{
		while (utils->x < data->x_dest && utils->y > data->y_dest
			&& utils->x > 0 && utils->y > 0)
		{
			my_mlx_pixel_put(data, utils->x, utils->y, 0x000000FF);
			utils->x += utils->dx;
			utils->y += utils->dy;
		}
	}
	else
	{
		while (utils->x < data->x_dest && utils->y < data->y_dest
			&& utils->x > 0 && utils->y > 0)
		{
			my_mlx_pixel_put(data, utils->x, utils->y, 0x000000FF);
			utils->x += utils->dx;
			utils->y += utils->dy;
		}
	}
}

void	cast_ray_2d(t_map *data)
{
	t_utils	*utils;

	utils = malloc(sizeof(t_utils));
	utils->x = data->p_x * data->tile_size + data->tile_size / 2;
	utils->y = data->p_y * data->tile_size + data->tile_size / 2;
	utils->step_size = 1;
	utils->dx = cos(data->ray_angle) * utils->step_size;
	utils->dy = sin(data->ray_angle) * utils->step_size;
	if (utils->x > data->x_dest)
		casting(data, utils);
	else
		casting_again(data, utils);
	free(utils);
}

void	cast_all_rays(t_map *data)
{
	int	i;

	i = 0;
	data->ray_angle = get_ray_angle(data);
	while (i < data->win_width)
	{
		raycasting(data);
		wall_projection(data, i);
		data->ray_angle += data->fov / data->win_width;
		i++;
	}
}
