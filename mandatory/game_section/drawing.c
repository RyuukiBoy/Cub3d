/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:06:30 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/28 19:11:11 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_map(t_map *data)
{
	data->x = 0;
	while (data->x < data->win_width)
	{
		data->y = 0;
		while (data->y < data->win_height)
		{
			if (data->map_tot[data->y / data->tile_size][data->x
				/ data->tile_size] == '1')
				my_mlx_pixel_put(data, data->x, data->y, 0x00FF0000);
			else
				my_mlx_pixel_put(data, data->x, data->y, 0xFFFFFF);
			if (data->x % data->tile_size == 0 || data->y
				% data->tile_size == 0)
				my_mlx_pixel_put(data, data->x, data->y, 0x000000);
			data->y++;
		}
		data->x++;
	}
}

void	draw_player(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->tile_size)
	{
		j = 0;
		while (j < data->tile_size)
		{
			if (sqrt(pow((data->p_x * data->tile_size + data->tile_size / 2)
						- (data->p_x * data->tile_size + j), 2) + pow((data->p_y
							* data->tile_size + data->tile_size / 2)
						- (data->p_y * data->tile_size + i),
						2)) <= data->radius)
				my_mlx_pixel_put(data, data->p_x * data->tile_size + j,
					data->p_y * data->tile_size + i, 0x000000FF);
			j++;
		}
		i++;
	}
}

void	render_map(t_map *data)
{
	draw_map(data);
	draw_player(data);
	cast_all_rays(data);
}
