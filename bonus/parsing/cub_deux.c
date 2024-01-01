/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_deux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:14:38 by ybouzafo          #+#    #+#             */
/*   Updated: 2024/01/01 17:48:44 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_line_one(char *line)
{
	if (line[0] == '\n')
		return (5);
	if (line[0] == '1' || line[0] == ' ')
		return (2);
	if (line[0] != ' ' && line[0] != '\n' && line[0] != 'N' && line[0] != 'S'
		&& line[0] != 'E' && line[0] != 'W' && line[0] != 'F' && line[0] != 'C'
		&& line[0] != '\0')
	{
		return (-1);
	}
	return (1);
}

int	first_map(char *line)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			return (1);
		}
	}
	else if (line[i] == '1')
		return (1);
	return (0);
}

void	check_virg(char *tmp, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		print_error("ERROR : colors ", map);
}
