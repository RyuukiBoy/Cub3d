/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:01:05 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:56 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	ft_search(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_read(int fd, char *res)
{
	int		count;
	char	*buf;
	char	*temp;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (free(res), free(buf), NULL);
		buf[count] = '\0';
		temp = ft_strjoin(res, buf);
		free(res);
		res = temp;
		if (count <= 0 || ft_search(buf))
			break ;
	}
	free(buf);
	if (!(*res))
		return (free(res), NULL);
	return (res);
}

static char	*ft_res(char *res)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	if (!res[i])
		return (free(res), NULL);
	str = (char *)malloc(ft_strlen(res) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (res[i])
		str[j++] = res[i++];
	str[j] = '\0';
	free(res);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

static char	*ft_ster(char *res)
{
	char	*ster;
	int		i;
	int		j;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	ster = (char *)malloc(i + 1);
	if (!ster)
		return (NULL);
	j = 0;
	while (res[j] && j < i)
	{
		ster[j] = res[j];
		j++;
	}
	ster[j] = '\0';
	return (ster);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*ster;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read(fd, res);
	if (!res)
		return (NULL);
	ster = ft_ster(res);
	res = ft_res(res);
	return (ster);
}
