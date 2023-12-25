/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:25 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/24 09:56:57 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init3dprojection(t_data *data)
{
    data->perp_dist = data->distance * cos(data->ray_angle - data->rotation_angle);
    data->dist_proj_plane = (data->win_width / 2) / tan(data->fov / 2);
    data->proj_wall_height = (data->tile_size / data->perp_dist) * data->dist_proj_plane;
    data->wall_strip_height = (int)data->proj_wall_height;
    data->wall_top_pixel = (data->win_height / 2) - (data->wall_strip_height / 2);
    data->wall_bottom_pixel = (data->win_height / 2) + (data->wall_strip_height / 2);
}

void    wall_projection(t_data *data, int i)
{
    int j;

    init3dprojection(data);
    if (data->wall_top_pixel < 0)
        data->wall_top_pixel = 0;
    if (data->wall_bottom_pixel > data->win_height)
        data->wall_bottom_pixel = data->win_height;
    j = data->wall_top_pixel;
    while (j < data->wall_bottom_pixel)
    {
        if (data->was_hit_vertical)
            my_mlx_pixel_put(data, i, j, 0x5C4033);
        else
            my_mlx_pixel_put(data, i, j, 0x964B00);
        j++;
    }
    j = 0;
    while (j < data->wall_top_pixel)
    {
        my_mlx_pixel_put(data, i, j, 0x87CEEB);
        j++;
    }
    j = data->wall_bottom_pixel;
    while (j < data->win_height)
    {
        my_mlx_pixel_put(data, i, j, 0xd3d3d3);
        j++;
    }
}

