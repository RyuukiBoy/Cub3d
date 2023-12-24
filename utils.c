/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:53:02 by oait-bad          #+#    #+#             */
/*   Updated: 2023/12/21 17:18:33 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_row(char *file)
{
	t_data	len;
	int		fd;
	char	*line;

	len.map_rows = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (line == NULL)
			break ;
		len.map_rows++;
	}
	free(line);
	return (len.map_rows);
}

int	count_col(char *file)
{
	t_data	len;
	int		fd;
	char	*line;

	len.map_cols = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line[len.map_cols])
		len.map_cols++;
	if (line[len.map_cols - 1] == '\n')
		len.map_cols--;
	free(line);
	return(len.map_cols);
}

int map_width(char **map)
{
    int i;
    int j;
    int max;

    i = 0;
    max = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
            j++;
        if (j > max)
            max = j;
        i++;
    }
    return (max);
}

int map_height(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

char    **read_map(char *file)
{
    char    **map;
    int     fd;
    int     i;
    char    *line;

    fd = open(file, O_RDONLY);
    i = 0;
    map = (char **)malloc(sizeof(char *) * (count_row(file) + 1));
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    free(line);
    map[i] = NULL;
    return (map);
}

float   get_ray_angle(t_data *data)
{
    float ray_angle;

    ray_angle = data->rotation_angle - (data->fov / 2);
    if (ray_angle < 0)
        ray_angle += 2 * M_PI;
    if (ray_angle > 2 * M_PI)
        ray_angle -= 2 * M_PI;
    return (ray_angle);
}

float   normalize_angle(float angle)
{
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

float distance_bt_points(float x1, float  y1, float x2, float y2)
{
    return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}
