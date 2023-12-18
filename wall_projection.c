/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:25 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/18 14:33:28 by oait-bad         ###   ########.fr       */
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
    data->wall_top_pixel = data->wall_top_pixel < 0 ? 0 : data->wall_top_pixel;
    data->wall_bottom_pixel = (data->win_height / 2) + (data->wall_strip_height / 2);
    data->wall_bottom_pixel = data->wall_bottom_pixel > data->win_height ? data->win_height : data->wall_bottom_pixel;
}

void draw_sky_fool(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->win_width)
    {
        j = 0;
        while (j < data->win_height)
        {
            if (j < data->win_height / 2)
                my_mlx_pixel_put(data, i, j, 0x000000FF);
            else
                my_mlx_pixel_put(data, i, j, 0x0000FF00);
            j++;
        }
    }
}

// void    wall_projection(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
    // init3dprojection(data);
    // while (i < data->win_width)
    // {
    //     j = 0;
    //     while (j < data->win_height)
    //     {
    //         if (j < data->wall_top_pixel)
    //             data->color_buffer[(data->win_width * j) + i] = 0x0000FF00;
    //         else if (j > data->wall_top_pixel && j < data->wall_bottom_pixel)
    //         {
                
    //             data->color_buffer[(data->win_width * j) + i] = 0xFFFFFF;
    //         }
    //         else
    //             data->color_buffer[(data->win_width * j) + i] = 0x0000FF00;
    //         my_mlx_pixel_put(data, i, j, data->color_buffer[(data->win_width * j) + i]);
    //         j++;
    //     }
    //     i++;
    // }
// }
