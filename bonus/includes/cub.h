/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:32 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/29 17:07:06 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "keycodes.h"
# include "math.h"
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6

# endif

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;
typedef struct s_utils
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		step_size;
}				t_utils;

typedef struct s_textures
{
	int			no;
	int			so;
	int			ea;
	int			we;
	t_img		*no_img;
	t_img		*so_img;
	t_img		*ea_img;
	t_img		*we_img;
	char		**no_map;
}				t_textures;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_fc
{
	int			fl;
	int			ce;
	char		*floor;
	char		*ceiling;
	t_rgb		*floor_rgb;
	t_rgb		*ceiling_rgb;
}				t_fc;

typedef struct s_map
{
	char		*posi_no;
	char		*posi_so;
	char		*posi_we;
	char		*posi_ea;
	char		*col_f;
	char		*col_c;
	int			len_col;
	char		**map_tot;
	char		**map;
	int			h;
	int			var1;
	int			check_new;
	int			var2;
	int			len;
	int			var3;
	int			var4;
	char		*ptr;
	size_t		len_nor;
	size_t		c_len_nor;
	size_t		j_nor;
	int			k_nor;
	char		*new_line;
	int			check_n;
	int			check_s;
	int			check_w;
	int			check_e;
	int			check_f;
	int			check_c;
	// ray cast
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	int			color;
	int			x;
	int			y;
	int			tile_x;
	int			tile_y;
	int			tile_size;
	int			win_width;
	int			win_height;
	size_t		map_rows;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		p_x;
	float		p_y;
	int			radius;
	float		turn_direction;
	float		walk_direction;
	float		strafe_direction;
	float		sliding;
	float		rotation_angle;
	float		move_speed;
	float		rotation_speed;
	float		x_step;
	float		y_step;
	int			num_rays;
	float		fov;
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	float		horz_distance;
	float		vert_distance;
	float		horz_x;
	float		horz_y;
	int			was_hit_horizontal;
	int			was_hit_vertical;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	// new adds
	float		x_intercept;
	float		y_intercept;
	float		x_ver_intercept;
	float		y_ver_intercept;
	float		x_ver_step;
	float		y_ver_step;
	float		vert_x;
	float		vert_y;
	float		wall_vert_x;
	float		wall_vert_y;
	float		x_dest;
	float		y_dest;
	float		perp_dist;
	float		dist_proj_plane;
	float		proj_wall_height;
	int			wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	int			vert_content;
	int			horz_content;
	int			found_horz_wall_hit;
	int			found_vert_wall_hit;
	int			wall_hit_content;
	// texture
	t_textures	*textures;
	t_fc		*fc;
	t_rgb		*rgb;
	int			textures_x;
	int			mouse_x;
}				t_map;
// pars
void			ft_close(t_map *map);
t_img			*new_img(t_map *data, char *path);
int				ft_exit(int *key);
void			init_img(t_map *map);
int				check_line_one(char *line);
void			valid_path_texture(t_map *map);
void			check_texture(t_map *map);
int				first_map(char *line);
void			check_color_err(t_map *map);
char			*ft_strcopy(char *dest, char *src);
void			check_dub_char(char *line, t_map *map);
void			check_double_char(char *line, t_map *map);
void			function_initialisation(t_map *map);
int				check_norm_deux(char *line, t_map *map);
void			exit_fail(void);
void			get_map(t_map *map, char **av);
char			*get_next_line(int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t l);
void			check_map(t_map *map);
void			ft_free(char **str);
void			check_map_length(t_map *map);
int				len_max(t_map *map);
void			check_i(t_map *map);
void			check_walls(t_map *map);
void			check_len_i(t_map *map);
void			check_len_j(t_map *map);
void			check_space_errors(t_map *map);
void			check_player(t_map *map);
size_t			ft_strlenn(char **ptr);
size_t			ft_strleen(char **ptr);
void			error_print(char *str);
char			*ft_strttcpy(char *dest, char *src);
void			check_walls(t_map *map);
char			*ft_strcopy(char *dest, char *src);
void			check_allmap(t_map *map);
void			func_initial(t_map *map);
char			*ft_strcopy(char *dest, char *src);
void			ft_free(char **str);
void			get_map(t_map *map, char **av);
void			first(char *line, t_map *map, char *tmp);
void			func_initial(t_map *map);
void			print_error(char *str);
char			*skip_space(char *line);
void			check_double_char(char *line, t_map *map);
void			check_dub_char(char *line, t_map *map);
void			check_player_second(t_map *map);
int				check_err_col_c(char *line, t_map *map);
int				check_err_col_f(char *line, t_map *map);

// ray casting
void			init_data(t_map *data);
void			get_player_pos(t_map *data);
int				key_press(int keycode, t_map *data);
int				key_release(int keycode, t_map *data);
// update

int				update(t_map *data);
void			move_player(t_map *data);
int				custom_round(float value);
int				is_wall(t_map *data, float x, float y);
// render map
void			render_map(t_map *data);
void			draw_map(t_map *data);
void			draw_player(t_map *data);
void			my_mlx_pixel_put(t_map *data, int x, int y, int color);
// cast rays
void			cast_all_rays(t_map *data);
void			cast_ray(t_map *data);
float			normalize_angle(float angle);
float			distance_bt_points(float x1, float y1, float x2, float y2);
float			get_ray_angle(t_map *data);
void			init_directions(t_map *data, float ray_angle);
void			set_horizontal_calculation(t_map *data);
void			get_horizontal_wallhit(t_map *data);
void			set_vertical_calculation(t_map *data);
void			get_vertical_wallhit(t_map *data);
char			*ft_strtrim_to_free(char *str, char *ptr);
// ray_norm
void			cast_ray_2d(t_map *data);
void			casting_again(t_map *data, t_utils *utils);
void			casting(t_map *data, t_utils *utils);
void			wall_projection(t_map *data, int i);
// ray_two
void			ft_texture(t_map *data, t_img *texture);
void			init3dprojection(t_map *data);
void			raycasting(t_map *data);
void			ray_facing_checker(t_map *data, float *horz_distance,
					float *vert_distance);
void			vert_cast(t_map *data);
// ray_three
void			horz_cast_1(t_map *data, float *nexttouchhorz_x,
					float *nexttouchhorz_y);
void			horz_cast_2(t_map *data, float *nexttouchhorz_x,
					float *nexttouchhorz_y);
void			horz_cast(t_map *data);
void			vert_cast_1(t_map *data, float *nexttouchvert_x,
					float *nexttouchvert_y);
void			vert_cast_2(t_map *data, float *nexttouchvert_x,
					float *nexttouchvert_y);
// engine
void			init_directions(t_map *data, float ray_angle);
void			horz_intercepts(t_map *data, float *nexttouchhorz_x,
					float *nexttouchhorz_y);
void			vert_intercepts(t_map *data, float *nexttouchvert_x,
					float *nexttouchvert_y);

int				create_rgb(int r, int g, int b);
int mouse_move(int x, int y, t_map *data);
void	move_player_bonus(t_map *data);
void	slide_leftside(t_map *data);
void	slide_rightside(t_map *data);

#endif