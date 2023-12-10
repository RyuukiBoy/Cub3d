/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:01:08 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/10 17:30:49 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    get_player_pos(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->map_rows)
    {
        j = 0;
        while (j < data->map_cols)
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                data->p_x = j;
                data->p_y = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    draw_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->tile_size)
    {
        j = 0;
        while (j < data->tile_size)
        {
            if (sqrt(pow((data->p_x * data->tile_size + data->tile_size / 2) - (data->p_x * data->tile_size + j), 2) + pow((data->p_y * data->tile_size + data->tile_size / 2) - (data->p_y * data->tile_size + i), 2)) <= data->radius)
                my_mlx_pixel_put(data, data->p_x * data->tile_size + j, data->p_y * data->tile_size + i, 0x000000FF);
            j++;
        }
        i++;
    }
}


void    draw_map(t_data *data)
{
    data->x = 0;
    while (data->x < data->win_width)
    {
        data->y = 0;
        while (data->y < data->win_height)
        {
            if (data->map[data->y / data->tile_size][data->x / data->tile_size] == '1')
                my_mlx_pixel_put(data, data->x, data->y, 0x00FF0000);
            else
                my_mlx_pixel_put(data, data->x, data->y, 0xFFFFFF);
            if (data->x % data->tile_size == 0 || data->y % data->tile_size == 0)
                my_mlx_pixel_put(data, data->x, data->y, 0x000000);
            data->y++;
        }
        data->x++;
    }
}

void    render_map(t_data *data)
{
    draw_map(data);
    draw_player(data);
    cast_all_rays(data);
    // ray_facing_checker(data);
}
