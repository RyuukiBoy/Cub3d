/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:28:07 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/29 13:40:25 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int mouse_move(int x, int y, t_map *data)
{
    if (x < 0 || x > data->win_width || y < 0 || y > data->win_height)
        return (0);
    if (data->mouse_x != x)
    {
        if (data->mouse_x < x)
            data->rotation_angle += 0.1;
        else
            data->rotation_angle -= 0.1;
    }
    data->mouse_x = x;
    return (0);
}

