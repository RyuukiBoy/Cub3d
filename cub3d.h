/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:58:35 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/24 15:55:12 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/gnl.h"
# include "keycodes.h"

typedef struct s_ray t_ray;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     width;
    int     height;
    unsigned int     *color_buffer;
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
    double distance;
    float horz_x;
    float horz_y;
    int was_hit_horizontal;
    int was_hit_vertical;
    int wall_hit_content;
    int vert_content;
    int horz_content;
    int found_horz_wall_hit;
    int found_vert_wall_hit;
    int is_ray_facing_up;
    int is_ray_facing_down;
    int is_ray_facing_left;
    int is_ray_facing_right;
    // new adds
    float x_intercept;
    float y_intercept;
    float x_ver_intercept;
    float y_ver_intercept;
    float x_ver_step;
    float y_ver_step;
    float vert_x;
    float vert_y;
    float wall_vert_x;
    float wall_vert_y;
    float x_dest;
    float y_dest;
    float perp_dist;
    float dist_proj_plane;
    float proj_wall_height;
    int wall_strip_height;
    int wall_top_pixel;
    int wall_bottom_pixel;
}               t_data;


typedef struct s_utils
{
    float   x;
    float   y;
    float   dx;
    float   dy;
    float   step_size;
}               t_utils;

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
void    raycasting(t_data *data);
void    cast_all_rays(t_data *data);
float   normalize_angle(float angle);
void    check_get_intercepts(t_data *data);
// void    ray_facing_checker(t_data *data);
void    ray_facing_checker2(t_data *data);
// void    ray_facing_checker(t_data *data, float horz_dis, float vert_dis);
void    upRight_upLeft_checker(t_data *data);
void    upLeft_downLeft_checker(t_data *data);
void    get_intercepts(t_data *data);
int     is_wall(t_data *data, float x, float y);
float   get_ray_angle(t_data *data);
float   distance_bt_points(float x1, float y1, float x2, float y2);
void    wall_projection(t_data *data, int i);
void    init_data(t_data *data, char **argv);
void    render_3d_screen(t_data *data);
void    render_color_buffer(t_data *t_data);
void    distance_adjustement(t_data *data);
void    vert_intersection(t_data *data);
void    horz_intersection(t_data *data);

#endif

