/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:08:30 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/24 11:14:28 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    casting(t_data *data, t_utils utils)
{
    if (utils.y > data->y_dest)
    {
        while (utils.x > data->x_dest && utils.y > data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    }
    else
    {
        while (utils.x > data->x_dest && utils.y < data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    }
}

void    casting_again(t_data *data, t_utils utils)
{
    if (utils.y > data->y_dest)
    {
        while (utils.x < data->x_dest && utils.y > data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    }
    else
    {
        while (utils.x < data->x_dest && utils.y < data->y_dest && utils.x > 0 && utils.y > 0)
        {
            my_mlx_pixel_put(data, utils.x, utils.y, 0x000000FF);
            utils.x += utils.dx;
            utils.y += utils.dy;
        }
    }
}

void    cast_ray(t_data *data)
{
    t_utils utils;

    utils.x = data->p_x * data->tile_size + data->tile_size / 2;
    utils.y = data->p_y * data->tile_size + data->tile_size / 2;
    utils.step_size = 1;
    utils.dx = cos(data->ray_angle) * utils.step_size;
    utils.dy = sin(data->ray_angle) * utils.step_size;
    if (utils.x > data->x_dest)
        casting(data, utils);
    else
        casting_again(data, utils);
}

void    cast_all_rays(t_data *data)
{
    int     i;

    i = 0;
    data->ray_angle = get_ray_angle(data);
    while (i < data->win_width)
    {
        ray_facing_checker(data);
        // cast_ray(data);
        wall_projection(data, i);
        data->ray_angle += data->fov / data->win_width;
        i++;
    }
}
