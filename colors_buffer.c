/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:18:44 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/17 10:38:27 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_color_buffer(t_data *t_data, unsigned int color)
{
    int i;
    int j;

    i = 0;
    while (i < t_data->win_width)
    {
        j = 0;
        while (j < t_data->win_height)
        {
            t_data->color_buffer[(t_data->win_width * j) + i] = color;
            j++;
        }
        i++;
    }
}

void    render_color_buffer(t_data *t_data)
{
    int i;
    int j;

    i = 0;
    while (i < t_data->win_width)
    {
        j = 0;
        while (j < t_data->win_height)
        {
            my_mlx_pixel_put(t_data, i, j, t_data->color_buffer[(t_data->win_width * j) + i]);
            j++;
        }
        i++;
    }
}
