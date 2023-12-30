/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:09:20 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:50 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_strncmp(const char *s1, const char *s2, size_t l)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*t;

	i = 0;
	s = (unsigned char *)s1;
	t = (unsigned char *)s2;
	while (i < l && (s[i] != '\0' || t[i] != '\0'))
	{
		if (s[i] != t[i])
		{
			return (s[i] - t[i]);
		}
		i++;
	}
	return (0);
}
