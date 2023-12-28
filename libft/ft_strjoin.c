/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:59:57 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/21 13:48:49 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (p && s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (p && s2 && s2[j])
	{
		p[i++] = s2[j++];
	}
	if (p)
		p[i] = 0;
	return (p);
}
