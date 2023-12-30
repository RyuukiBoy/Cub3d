/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:00:08 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/01/05 17:44:51 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word(char const *str, char d)
{
	int	i;
	int	mo;
	int	len;

	len = ft_strlen(str);
	i = 0;
	mo = 0;
	while (i < len)
	{
		if (str[i] != d)
		{
			while (str[i] != d && i < len)
				i++;
			mo++;
		}
		i++;
	}
	return (mo);
}

static size_t	ft_wlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**str;

	i = 0;
	start = -1;
	if (!s)
		return (0);
	str = (char **)malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++start < ft_word(s, c))
	{
		while (s[i] == c)
			i++;
		str[start] = ft_substr(s, i, ft_wlen(s, c, i));
		if (str[start] == NULL)
		{
			ft_free(str);
			return (NULL);
		}
		i = i + ft_wlen(s, c, i);
	}
	str[start] = 0;
	return (str);
}
