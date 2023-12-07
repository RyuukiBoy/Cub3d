/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:08:30 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/04 21:08:52 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    cast_ray(t_data *data, float ray_angle)
{
    float   x;
    float   y;
    float   dx;
    float   dy;
    float   step_size;

    x = data->p_x * data->tile_size + data->tile_size / 2;
    y = data->p_y * data->tile_size + data->tile_size / 2;
    step_size = 0.1;
    dx = cos(ray_angle) * step_size;
    dy = sin(ray_angle) * step_size;
    while (x < data->win_width && y < data->win_height && x > 0 && y > 0)
    {
        my_mlx_pixel_put(data, x, y, 0x000000FF);
        x += dx;
        y += dy;
    }
}

void    cast_all_rays(t_data *data)
{
    float   fov;
    float   ray_angle;
    int     i;
    int     num_rays;

    i = 0;
    fov = 60 * (M_PI / 180);
    num_rays = data->win_width / 5;
    while (i < num_rays)
    {
        ray_angle = data->rotation_angle - (fov / 2) + (i * fov / num_rays);
        cast_ray(data, ray_angle);
        i++;
    }
}
