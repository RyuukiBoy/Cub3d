/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:52:36 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/31 11:06:50 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	vert_wall_hit(t_map *data, float *nextvert_x, float *nextvert_y)
{
	data->found_vert_wall_hit = 1;
	data->wall_vert_x = *nextvert_x;
	data->wall_vert_y = *nextvert_y;
	data->vert_content = data->map_tot[(int)(*nextvert_y
			/ data->tile_size)][(int)(*nextvert_x
			/ data->tile_size) - 1];
}

void	horz_wall_hit(t_map *data, float *nexthorz_x, float *nexthorz_y)
{
	data->found_horz_wall_hit = 1;
	data->wall_hit_x = *nexthorz_x;
	data->wall_hit_y = *nexthorz_y;
	data->horz_content = data->map_tot[(int)(*nexthorz_y
			/ data->tile_size) - 1][(int)(*nexthorz_x
			/ data->tile_size)];
}
