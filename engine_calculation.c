/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:12 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/15 10:45:16 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_directions(t_data *data, float ray_angle)
{
    ray_angle = normalize_angle(ray_angle);
    data->is_ray_facing_down =  ray_angle > 0 &&  ray_angle < M_PI;
    data->is_ray_facing_up = !data->is_ray_facing_down;
    data->is_ray_facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI ;
    data->is_ray_facing_left = !data->is_ray_facing_right;
}

void    set_horizontal_calculation(t_data *data)
{
    float   x;
    float   y;

    x = data->p_x * data->tile_size + data->tile_size / 2;
    y = data->p_y * data->tile_size + data->tile_size / 2;
    data->y_intercept = floor(y / data->tile_size) * data->tile_size;
    if (data->is_ray_facing_down)
        data->y_intercept += data->tile_size;
    data->x_intercept = x + (data->y_intercept - y) / tan(data->ray_angle);
    data->y_step = data->tile_size;
    if(data->is_ray_facing_up)
        data->y_step *= -1;
    data->x_step = data->tile_size / tan(data->ray_angle);
    if(data->is_ray_facing_left && data->x_step > 0)
        data->x_step *= -1;
    if(data->is_ray_facing_right && data->x_step < 0)
        data->x_step *= -1;
    data->horz_x = data->x_intercept;
    data->horz_y = data->y_intercept;
}

void    get_horizontal_wallhit(t_data *data)
{
    float   xtocheck;
    float   ytocheck;

    init_directions(data, data->ray_angle);
    set_horizontal_calculation(data);
    while ((int)data->horz_x >= 0 && (int)data->horz_x <= (int)data->win_width && (int)data->horz_y >= 0 && (int)data->horz_y <= (int)data->win_height)
    {
        xtocheck = data->horz_x;
        ytocheck = data->horz_y;
        if(data->is_ray_facing_up)
            ytocheck = data->horz_y - 1;
        if (data->map[(int)((ytocheck) / 42)][(int)((xtocheck) /42)] == '1')
        { 
            data->was_hit_horizontal = 1;
            data->wall_hit_x = xtocheck;
            data->wall_hit_y = ytocheck;
            break ;
        }
        else
        {
            data->horz_x += data->x_step;
            data->horz_y += data->y_step;
        }
    }
}

void    set_vertical_calculation(t_data *data)
{
    float   a;
    float   b;

    a = data->p_x * data->tile_size + data->tile_size / 2;
    b = data->p_y * data->tile_size + data->tile_size / 2;
    data->x_ver_intercept = floor(a / data->tile_size) * data->tile_size;
    if(data->is_ray_facing_right)
        data->x_ver_intercept += data->tile_size;
    data->y_ver_intercept = b + (data->x_ver_intercept - a) * tan(data->ray_angle);
    data->x_ver_step = data->tile_size;
    if(data->is_ray_facing_left)
        data->x_ver_step *= -1;
    data->y_ver_step = data->tile_size * tan(data->ray_angle);
    if(data->is_ray_facing_up && data->y_ver_step > 0)
        data->y_ver_step *= -1;
    if(data->is_ray_facing_down && data->y_ver_step < 0)
       data->y_ver_step *= -1;
    data->vert_x = data->x_ver_intercept;
    data->vert_y = data->y_ver_intercept;
}

void    get_vertical_wallhit(t_data *data)
{
    float  xtocheck;
    float  ytocheck;

    init_directions(data, data->ray_angle);
    set_vertical_calculation(data);
    while (data->vert_x >= 0 && data->vert_x <= data->win_width && data->vert_y >= 0 && data->vert_y <= data->win_height)
    {   
        xtocheck = data->vert_x;
        if(data->is_ray_facing_left)
            xtocheck = data->vert_x - 1;
        ytocheck = data->vert_y;
        if (data->map[(int)((ytocheck) / 42)][(int)((xtocheck) /42)] == '1')
        { 
            data->was_hit_vertical = 1;
            data->wall_vert_x = data->vert_x;
            data->wall_vert_y = data->vert_y;
            break ;
        }
        else
        {
            data->vert_x += data->x_ver_step;
            data->vert_y += data->y_ver_step;
        }
    }
}

void    ray_facing_checker(t_data *data)
{
    float horz_distance;
    float vert_distance;

    get_horizontal_wallhit(data);
    get_vertical_wallhit(data);
    horz_distance = distance_bt_points(data->p_x * data->tile_size + data->tile_size / 2, data->p_y * data->tile_size + data->tile_size / 2, data->wall_hit_x , data->wall_hit_y);
    vert_distance = distance_bt_points(data->p_x * data->tile_size + data->tile_size / 2, data->p_y * data->tile_size + data->tile_size / 2, data->wall_vert_x , data->wall_vert_y);
    if(vert_distance < horz_distance)
    {
        data->x_dest = data->wall_vert_x;
        data->y_dest = data->wall_vert_y;
    }
    else
    {
         data->x_dest = data->wall_hit_x;
         data->y_dest = data->wall_hit_y;
    }
}

