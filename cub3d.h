/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:58:35 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/10 13:59:49 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/gnl.h"
# include "keycodes.h"

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     width;
    int     height;
    int     color;
    int     x;
    int     y;
    int     tile_x;
    int     tile_y;
    int     tile_size;
    int     win_width;
    int     win_height;
    int     map_rows;
    int     map_cols;
    char    **map;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    float     p_x;
    float     p_y;
    int     radius;
    float     turn_direction;
    float     walk_direction;
    float     strafe_direction;
    float  rotation_angle;
    float  move_speed;
    float  rotation_speed;
    float x_step;
    float y_step;
    int num_rays;
    float fov;
    float ray_angle;
    float wall_hit_x;
    float wall_hit_y;
    float distance;
    float horz_x;
    float horz_y;
    int was_hit_horizontal;
    int is_ray_facing_up;
    int is_ray_facing_down;
    int is_ray_facing_left;
    int is_ray_facing_right;
    float x_intercept;
    float y_intercept;
}               t_data;

void    draw_map(t_data *data);
void    draw_player(t_data *data);
int	    count_col(char *file);
int	    count_row(char *file);
char    **read_map(char *file);
int     map_width(char **map);
int     map_height(char **map);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    get_player_pos(t_data *data);
void    render_map(t_data *data);
void    move_player(t_data *data);
int     update(t_data *data);
int     key_press(int keycode, t_data *data);
int     key_release(int keycode, t_data *data);
int     custom_round(float value);
void    cast_ray(t_data *data, float ray_angle);
void    cast_all_rays(t_data *data);
float   normalize_angle(float angle);
void    check_get_intercepts(t_data *data);
void    ray_facing_checker(t_data *data);
void    upRight_upLeft_checker(t_data *data);
void    upLeft_downLeft_checker(t_data *data);
void    get_intercepts(t_data *data);
int     is_wall(t_data *data, float x, float y);
float   get_ray_angle(t_data *data);

#endif