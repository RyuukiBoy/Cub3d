/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:13:18 by oait-bad          #+#    #+#             */
/*   Updated: 2024/01/08 20:38:29 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_press(int keycode, t_map *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		data->walk_direction = 1;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		data->walk_direction = -1;
	if (keycode == LEFT_KEY)
		data->turn_direction = -1;
	if (keycode == RIGHT_KEY)
		data->turn_direction = 1;
	if (keycode == A_KEY)
		data->strafe_direction = -1;
	if (keycode == D_KEY)
		data->strafe_direction = 1;
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

int	key_release(int keycode, t_map *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		data->walk_direction = 0;
	if (keycode == S_KEY || keycode == DOWN_KEY)
		data->walk_direction = 0;
	if (keycode == LEFT_KEY)
		data->turn_direction = 0;
	if (keycode == RIGHT_KEY)
		data->turn_direction = 0;
	if (keycode == A_KEY)
		data->strafe_direction = 0;
	if (keycode == D_KEY)
		data->strafe_direction = 0;
	return (0);
}

int	is_wall(t_map *data, float x, float y)
{
	size_t	mapx;
	size_t	mapy;

	mapx = (int)x;
	mapy = (int)y;
	if (mapx < 0 || mapx >= data->len_nor || mapy < 0 || mapy >= data->map_rows)
		return (2);
	if (data->map_tot[mapy][mapx] == '1' || data->map_tot[mapy][mapx] == ' ')
	{
		return (1);
	}
	return (0);
}

void	strafe_movement(t_map *data)
{
	float	new_p_x;
	float	new_p_y;

	data->rotation_angle += data->turn_direction * data->move_speed;
	new_p_x = data->p_x + cos(data->rotation_angle + M_PI_2)
		* data->strafe_direction * data->move_speed;
	new_p_y = data->p_y + sin(data->rotation_angle + M_PI_2)
		* data->strafe_direction * data->move_speed;
	if (!is_wall(data, custom_round(new_p_x), custom_round(new_p_y))
		&& !is_wall(data, custom_round(new_p_x), custom_round(data->p_y))
		&& !is_wall(data, custom_round(data->p_x), custom_round(new_p_y)))
	{
		data->p_x = new_p_x;
		data->p_y = new_p_y;
	}
}

void	move_player(t_map *data)
{
	float	new_p_x;
	float	new_p_y;

	data->rotation_angle += data->turn_direction * data->move_speed;
	new_p_x = data->p_x + cos(data->rotation_angle) * data->walk_direction
		* data->move_speed;
	new_p_y = data->p_y + sin(data->rotation_angle) * data->walk_direction
		* data->move_speed;
	if (!is_wall(data, custom_round(new_p_x), custom_round(new_p_y))
		&& !is_wall(data, custom_round(new_p_x), custom_round(data->p_y))
		&& !is_wall(data, custom_round(data->p_x), custom_round(new_p_y)))
	{
		data->p_x = new_p_x;
		data->p_y = new_p_y;
	}
	strafe_movement(data);
}
