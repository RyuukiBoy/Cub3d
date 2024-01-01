/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:25 by oait-bad          #+#    #+#             */
/*   Updated: 2024/01/01 17:41:53 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init3dprojection(t_map *data)
{
	data->perp_dist = data->distance * cos(data->ray_angle
			- data->rotation_angle);
	data->dist_proj_plane = (data->win_width / 2) / tan(data->fov / 2);
	data->proj_wall_height = (data->tile_size / data->perp_dist)
		* data->dist_proj_plane;
	data->wall_strip_height = (int)data->proj_wall_height;
	data->wall_top_pixel = (data->win_height / 2) - (data->wall_strip_height
			/ 2);
	data->wall_bottom_pixel = (data->win_height / 2) + (data->wall_strip_height
			/ 2);
	if (data->wall_top_pixel < 0)
		data->wall_top_pixel = 0;
	if (data->wall_bottom_pixel > data->win_height)
		data->wall_bottom_pixel = data->win_height;
}

void	ft_texture_2(t_map *data, t_img *texture)
{
	if (data->was_hit_vertical)
	{
		if (data->is_ray_facing_left)
			*texture = *(data->textures->ea_img);
		else
			*texture = *(data->textures->we_img);
		data->textures_x = (int)(data->y_dest * texture->width
				/ data->tile_size) % texture->width;
	}
	else
	{
		if (data->is_ray_facing_up)
			*texture = *(data->textures->so_img);
		else
			*texture = *(data->textures->no_img);
		data->textures_x = (int)(data->x_dest * texture->width
				/ data->tile_size) % texture->width;
	}
}

void	ft_texture(t_map *data, t_img *texture)
{
	if (data->was_hit_vertical)
	{
		*texture = *(data->textures->no_img);
		data->textures_x = (int)(data->x_dest * texture->width
				/ data->tile_size) % texture->width;
	}
	else
	{
		*texture = *(data->textures->we_img);
		data->textures_x = (int)(data->y_dest * texture->width
				/ data->tile_size);
	}
	ft_texture_2(data, texture);
}

void	floor_ceiling(t_map *data, int i)
{
	int	j;

	j = 0;
	while (j < data->wall_top_pixel)
		my_mlx_pixel_put(data, i, j++, data->fc->ce);
	j = data->wall_bottom_pixel;
	while (j < data->win_height)
		my_mlx_pixel_put(data, i, j++, data->fc->fl);
}

void	wall_projection(t_map *data, int i)
{
	int		j;
	int		texture_y;
	int		distance_top;
	char	*a;
	t_img	*texture;

	init3dprojection(data);
	j = data->wall_top_pixel;
	texture = malloc(sizeof(t_img));
	ft_texture(data, texture);
	while (j < data->wall_bottom_pixel)
	{
		distance_top = j + (data->proj_wall_height / 2) - (data->win_height
				/ 2);
		texture_y = (int)(distance_top * (float)(texture->height
					/ data->proj_wall_height));
		a = texture->addr + (texture_y * texture->line_length)
			+ (data->textures_x * (texture->bits_per_pixel / 8));
		my_mlx_pixel_put(data, i, j, *(unsigned int *)a);
		j++;
	}
	floor_ceiling(data, i);
	free(texture);
}
