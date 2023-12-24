/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:16:12 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/24 15:58:38 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_directions(t_data *data, float ray_angle)
{
    data->is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
    data->is_ray_facing_up = !data->is_ray_facing_down;
    data->is_ray_facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
    data->is_ray_facing_left = !data->is_ray_facing_right;
}

void    horz_cast_1(t_data *data, float *nexttouchhorz_x, float *nexttouchhorz_y)
{
    if (data->is_ray_facing_down)
    {
        while (*nexttouchhorz_y >= 0 && *nexttouchhorz_x >= 0 && *nexttouchhorz_y < data->win_height && *nexttouchhorz_x < data->win_width)
        {
            if (data->map[(int)(*nexttouchhorz_y / data->tile_size)][(int)(*nexttouchhorz_x / data->tile_size)] == '1') 
            {
                data->found_horz_wall_hit = 1;
                data->wall_hit_x = *nexttouchhorz_x;
                data->wall_hit_y = *nexttouchhorz_y;
                data->horz_content = data->map[(int)(*nexttouchhorz_y / data->tile_size)][(int)(*nexttouchhorz_x / data->tile_size)];
                break ;
            }
            else
            {
                *nexttouchhorz_x += data->x_step;
                *nexttouchhorz_y += data->y_step;
            }
        }
    }
}

void    horz_cast_2(t_data *data, float *nexttouchhorz_x, float *nexttouchhorz_y)
{
    if (data->is_ray_facing_up)
    {
        while (*nexttouchhorz_y >= 0 && *nexttouchhorz_x >= 0 && *nexttouchhorz_y < data->win_height && *nexttouchhorz_x < data->win_width)
        {
            if (data->map[(int)(*nexttouchhorz_y / data->tile_size) - 1][(int)(*nexttouchhorz_x / data->tile_size)] == '1') 
            {
                data->found_horz_wall_hit = 1;
                data->wall_hit_x = *nexttouchhorz_x;
                data->wall_hit_y = *nexttouchhorz_y;
                data->horz_content = data->map[(int)(*nexttouchhorz_y / data->tile_size) - 1][(int)(*nexttouchhorz_x / data->tile_size)];
                break ;
            }
            else
            {
                *nexttouchhorz_x += data->x_step;
                *nexttouchhorz_y += data->y_step;
            }
        }
    }
}

//////////// Had joj functions lfo9 khdit bihom wall hit fach kaykon ray kaychof lfo9 w lte7t

void    horz_intercepts(t_data *data, float *nexttouchhorz_x, float *nexttouchhorz_y)
{
    float x_intercept;
    float y_intercept;
    float x;
    float y;

    x = data->p_x * data->tile_size + data->tile_size / 2;
    y = data->p_y * data->tile_size + data->tile_size / 2;
    y_intercept = floor(y / data->tile_size) * data->tile_size;
    if (data->is_ray_facing_down)
        y_intercept += data->tile_size;
    x_intercept = x + (y_intercept - y) / tan(data->ray_angle);
    data->y_step = data->tile_size;
    if (!data->is_ray_facing_down)
        data->y_step *= -1;
    data->x_step = data->tile_size / tan(data->ray_angle);
    if (data->is_ray_facing_left && data->x_step > 0)
        data->x_step *= -1;
    if (data->is_ray_facing_right && data->x_step < 0)
        data->x_step *= -1;
    *nexttouchhorz_x = x_intercept;
    *nexttouchhorz_y = y_intercept;
}

void    horz_cast(t_data *data)
{
    float nexttouchhorz_x;
    float nexttouchhorz_y;

    data->found_horz_wall_hit = 0;
    horz_intercepts(data, &nexttouchhorz_x, &nexttouchhorz_y);
    horz_cast_1(data, &nexttouchhorz_x, &nexttouchhorz_y);
    horz_cast_2(data, &nexttouchhorz_x, &nexttouchhorz_y);
}

void    vert_cast_1(t_data *data, float *nexttouchvert_x, float *nexttouchvert_y)
{
    if (data->is_ray_facing_right)
    {
        while (*nexttouchvert_y >= 0 && *nexttouchvert_x >= 0 && *nexttouchvert_y < data->win_height && *nexttouchvert_x < data->win_width)
        {
            if (data->map[(int)(*nexttouchvert_y / data->tile_size)][(int)(*nexttouchvert_x / data->tile_size)] == '1') 
            {
                data->found_vert_wall_hit = 1;
                data->wall_vert_x = *nexttouchvert_x;
                data->wall_vert_y = *nexttouchvert_y;
                data->vert_content = data->map[(int)(*nexttouchvert_y / data->tile_size)][(int)(*nexttouchvert_x / data->tile_size)];
                break ;
            }
            else
            {
                *nexttouchvert_x += data->x_ver_step;
                *nexttouchvert_y += data->y_ver_step;
            }
        }
    }
}

void    vert_cast_2(t_data *data, float *nexttouchvert_x, float *nexttouchvert_y)
{
    if (data->is_ray_facing_left)
    {
        while (*nexttouchvert_y >= 0 && *nexttouchvert_x >= 0 && *nexttouchvert_y < data->win_height && *nexttouchvert_x < data->win_width)
        {
            if (data->map[(int)(*nexttouchvert_y / data->tile_size)][(int)(*nexttouchvert_x / data->tile_size) - 1] == '1') 
            {
                data->found_vert_wall_hit = 1;
                data->wall_vert_x = *nexttouchvert_x;
                data->wall_vert_y = *nexttouchvert_y;
                data->vert_content = data->map[(int)(*nexttouchvert_y / data->tile_size)][(int)(*nexttouchvert_x / data->tile_size) - 1];
                break ;
            }
            else
            {
                *nexttouchvert_x += data->x_ver_step;
                *nexttouchvert_y += data->y_ver_step;
            }
        }
    }
}

////////// hado li lfo9 nfss lblan dayl horizontal ghir hiya kantchecki left w right

void    vert_intercepts(t_data *data, float *nexttouchvert_x, float *nexttouchvert_y)
{
    float x_intercept;
    float y_intercept;
    float x;
    float y;

    x = data->p_x * data->tile_size + data->tile_size / 2;
    y = data->p_y * data->tile_size + data->tile_size / 2;
    x_intercept = floor(x / data->tile_size) * data->tile_size;
    if (data->is_ray_facing_right)
        x_intercept += data->tile_size;
    y_intercept = y + (x_intercept - x) * tan(data->ray_angle);
    data->x_ver_step = data->tile_size;
    if (!data->is_ray_facing_right)
        data->x_ver_step *= -1;
    data->y_ver_step = data->tile_size * tan(data->ray_angle);
    if (data->is_ray_facing_up && data->y_ver_step > 0)
        data->y_ver_step *= -1;
    if (data->is_ray_facing_down && data->y_ver_step < 0)
        data->y_ver_step *= -1;
    *nexttouchvert_x = x_intercept;
    *nexttouchvert_y = y_intercept;
}

void    vert_cast(t_data *data)
{
    float nexttouchvert_x;
    float nexttouchvert_y;

    data->found_vert_wall_hit = 0;
    vert_intercepts(data, &nexttouchvert_x, &nexttouchvert_y);
    vert_cast_1(data, &nexttouchvert_x, &nexttouchvert_y);
    vert_cast_2(data, &nexttouchvert_x, &nexttouchvert_y);
}

void    ray_facing_checker(t_data *data, float *horz_distance, float *vert_distance)
{
    float x;
    float y;
    
    x = data->p_x * data->tile_size + data->tile_size / 2;
    y = data->p_y * data->tile_size + data->tile_size / 2;
    if (data->found_horz_wall_hit)
        *horz_distance = distance_bt_points(x, y, data->wall_hit_x, data->wall_hit_y);
    else
        *horz_distance = INT_MAX;
    if (data->found_vert_wall_hit)
        *vert_distance = distance_bt_points(x, y, data->wall_vert_x, data->wall_vert_y);
    else
        *vert_distance = INT_MAX;
    if (*vert_distance < *horz_distance)
    {
        data->distance = *vert_distance;
        data->x_dest = data->wall_vert_x;
        data->y_dest = data->wall_vert_y;
        data->wall_hit_content = data->vert_content;
        data->was_hit_vertical = 1;
    }
    else
    {
        data->distance = *horz_distance;
        data->x_dest = data->wall_hit_x;
        data->y_dest = data->wall_hit_y;
        data->wall_hit_content = data->horz_content;
        data->was_hit_vertical = 0;
    }
}

////////// sf hna kanakhd dak distance 3adi kif kna dayrin 9bel w kna nssina dok les conditions dyal distance ymkn ta howa kaydir lina problem

void    raycasting(t_data *data)
{
    float   horz_distance;
    float   vert_distance;

    data->ray_angle = normalize_angle(data->ray_angle);
    init_directions(data, data->ray_angle);
    horz_cast(data);
    vert_cast(data);
    ray_facing_checker(data, &horz_distance, &vert_distance);
}

/////////// sf hadi hia function li knakhdm biha f cast_all_rays lakhrin 3tithom pointer bach ytbdl value dyalhom f had lfunctions kamlin 7it kaytdar lihom update fkol mra mal9ach wall
