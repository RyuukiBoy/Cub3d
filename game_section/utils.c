/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:40:18 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 19:00:08 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_img	*new_img(t_map *data, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		print_error("Error :allocation de memoire \n");
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width,
			&img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	init_img(t_map *map)
{
	map->textures->no_img = new_img(map, map->posi_no);
	map->textures->ea_img = new_img(map, map->posi_ea);
	map->textures->so_img = new_img(map, map->posi_so);
	map->textures->we_img = new_img(map, map->posi_we);
}

int	ft_exit(int *key)
{
	(void)key;
	exit(0);
}

char	*ft_strcopy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}
