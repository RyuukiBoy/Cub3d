/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:18:14 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/15 09:49:49 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == W_KEY || keycode == UP_KEY)
        data->walk_direction = 1;
    if (keycode == S_KEY || keycode == DOWN_KEY)
        data->walk_direction = -1;
    if (keycode == RIGHT_KEY)
        data->turn_direction = 1;
    if (keycode == LEFT_KEY)
        data->turn_direction = -1;
    if (keycode == D_KEY)
        data->strafe_direction = 1;
    if (keycode == A_KEY)
        data->strafe_direction = -1;
    if (keycode == ESC_KEY)
        exit(0);
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == W_KEY || keycode == UP_KEY)
        data->walk_direction = 0;
    if (keycode == S_KEY || keycode == DOWN_KEY)
        data->walk_direction = 0;
    if (keycode == RIGHT_KEY)
        data->turn_direction = 0;
    if (keycode == LEFT_KEY)
        data->turn_direction = 0;
    if (keycode == D_KEY)
        data->strafe_direction = 0;
    if (keycode == A_KEY)
        data->strafe_direction = 0;
    return (0);
}

int is_wall(t_data *data, float x, float y)
{
    int mapx;
    int mapy;

    mapx = (int)x;
    mapy = (int)y;
    if (mapx < 0 || mapx >= data->map_cols || mapy < 0 || mapy >= data->map_rows)
        return (2);

    // printf("....%c \n", data->map[mapy][mapx]);
    if (data->map[mapy][mapx] == '1')
        return (1);
    return (0);
}

int custom_round(float value)
{
    if (value < 0)
        return (int)(value - 0.5);
    else
        return (int)(value + 0.5);
}

void move_player(t_data *data)
{
    float new_player_x;
    float new_player_y;

    data->rotation_angle += data->turn_direction * data->move_speed;
    new_player_x = data->p_x + cos(data->rotation_angle) * data->walk_direction * data->move_speed;
    new_player_y = data->p_y + sin(data->rotation_angle) * data->walk_direction * data->move_speed;
    if (!is_wall(data, custom_round(new_player_x), custom_round(new_player_y)))
    {
        data->p_x = new_player_x;
        data->p_y = new_player_y;
    }
    new_player_x = data->p_x + cos(data->rotation_angle + M_PI_2) * data->strafe_direction * data->move_speed;
    new_player_y = data->p_y + sin(data->rotation_angle + M_PI_2) * data->strafe_direction * data->move_speed;
    if (!is_wall(data, custom_round(new_player_x), custom_round(new_player_y)))
    {
        data->p_x = new_player_x;
        data->p_y = new_player_y;
    }
}

int update(t_data *data)
{
    move_player(data);
    mlx_destroy_image(data->mlx_ptr, data->img_ptr);
    data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
    render_map(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    return (0);
}