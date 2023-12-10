/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:12 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/10 17:30:54 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float   normalize_angle(float angle)
{
    angle = remainder(angle, (2 * M_PI));
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

void    upRight_upLeft_checker(t_data *data)
{
    float     angle_updated;

    angle_updated = fmod(data->ray_angle, (2 * M_PI));
    if (angle_updated > 0 && angle_updated < M_PI)
    {
        data->is_ray_facing_down = 1;
        data->is_ray_facing_up = 0;
        if (data->is_ray_facing_down)
            data->y_intercept += data->tile_size;
    }
    else
    {
        data->is_ray_facing_down = 0;
        data->is_ray_facing_up = 1;
        if (data->is_ray_facing_up)
            data->y_step *= -1;
    }
}

void    upLeft_downLeft_checker(t_data *data)
{
    float     angle_updated;

    angle_updated = fmod(data->ray_angle, (2 * M_PI));
    if (angle_updated < 0.5 * M_PI || angle_updated > 1.5 * M_PI)
    {
        data->is_ray_facing_right = 1;
        data->is_ray_facing_left = 0;
        if (data->is_ray_facing_right && data->x_step < 0)
            data->x_step *= -1;
    }
    else
    {
        data->is_ray_facing_right = 0;
        data->is_ray_facing_left = 1;
        if (data->is_ray_facing_left && data->x_step > 0)
            data->x_step *= -1;
    }
}

// void    ray_facing_checker(t_data *data)
// {
//     data->y_intercept = floor(data->p_y / data->tile_size) * data->tile_size;
//     data->x_intercept = data->p_x + (data->y_intercept - data->p_y) / tan(data->ray_angle);
//     upRight_upLeft_checker(data);
//     upLeft_downLeft_checker(data);
//     data->horz_x = data->x_intercept;
//     data->horz_y = data->y_intercept;
//     if (data->is_ray_facing_up)
//         data->horz_y--;
//     while (data->horz_x >= 0 && data->horz_x <= data->win_width && data->horz_y >= 0 && data->horz_y <= data->win_height)
//     {
//         if (is_wall(data, data->horz_x, data->horz_y))
//         {
//             data->was_hit_horizontal = 1;
//             data->wall_hit_x = data->horz_x;
//             data->wall_hit_y = data->horz_y;
//             break ;
//         }
//         else
//         {
//             data->horz_x += data->x_step;
//             data->horz_y += data->y_step;
//         }
//     }
// } 
