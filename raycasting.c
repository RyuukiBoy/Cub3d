/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:08:30 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/15 10:53:41 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    casting(t_data *data, t_utils utils)
{
    if (utils.y > data->y_dest)
        while (utils.x > data->x_dest && utils.y > data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    else
        while (utils.x > data->x_dest && utils.y < data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
}

void    casting_again(t_data *data, t_utils utils)
{
    if (utils.y > data->y_dest)
        while (utils.x < data->x_dest && utils.y > data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    else
        while (utils.x < data->x_dest && utils.y < data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
}

void    cast_ray(t_data *data, float ray_angle)
{
    t_utils utils;

    utils.x = data->p_x * data->tile_size + data->tile_size / 2;
    utils.y = data->p_y * data->tile_size + data->tile_size / 2;
    utils.step_size = 0.1;
    utils.dx = cos(ray_angle) * utils.step_size;
    utils.dy = sin(ray_angle) * utils.step_size;
    ray_facing_checker(data);
    if (utils.x > data->x_dest)
        casting(data, utils);
    else
        casting_again(data, utils);
}

void    cast_all_rays(t_data *data)
{
    int     i;

    i = 0;
    while (i < data->num_rays)
    {
        data->ray_angle = get_ray_angle(data) + (i * data->fov / data->num_rays);
        cast_ray(data, data->ray_angle);
        i++;
    }
}
