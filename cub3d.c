/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:50:47 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/23 17:14:37 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_data(t_data *data, char **argv)
{
    data->x = 0;
    data->y = 0;
    data->tile_size = 60;
    data->map_cols = count_col(argv[1]);
    data->map_rows = count_row(argv[1]);
    data->win_width = data->map_cols * data->tile_size;
    data->win_height = data->map_rows * data->tile_size;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "cub3d");
    data->img_ptr = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
    data->map = read_map(argv[1]);
    data->width = map_width(data->map);
    data->height = map_height(data->map);
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
    data->x = data->win_width / 2;
    data->y = data->win_height / 2;
    data->radius = 5;
    data->turn_direction = 0;
    data->walk_direction = 0;
    data->rotation_angle = 3 * (M_PI / 2);
    data->move_speed = 0.07;
    data->rotation_speed = 2 * (M_PI / 180);
    data->num_rays = data->win_width / 5;
    // data->distance = 0;
    data->fov = 60 * (M_PI / 180);
    //new adds;
    // data->x_intercept = 0;
    // data->y_intercept = 0;
    // data->is_ray_facing_down = 0;
    // data->is_ray_facing_up = 0;
    // data->is_ray_facing_right = 0;
    // data->is_ray_facing_left = 0;
    // data->x_ver_intercept = 0;
    // data->y_ver_intercept = 0;
    data->was_hit_horizontal = 0;
    data->was_hit_vertical = 0;
    data->wall_hit_content = 0;
    data->vert_content = 0;
    data->horz_content = 0;
    // data->x_ver_step = 0;
    // data->y_ver_step = 0;
    // data->vert_x = 0;
    // data->vert_y = 0;
    // data->wall_vert_x = 0;
    // data->wall_vert_y = 0;
    // data->x_dest = 0;
    // data->y_dest = 0;
    data->color_buffer = (unsigned int *)malloc(sizeof(unsigned int) * data->win_width * data->win_height);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc != 2)
    {
        printf("Error: there is no map\n");
        return (1);
    }
    init_data(&data, argv);
    get_player_pos(&data);
    mlx_hook(data.win_ptr, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win_ptr, 3, 1L << 1, key_release, &data);
    mlx_loop_hook(data.mlx_ptr, update, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}
