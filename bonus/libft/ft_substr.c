/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:59:46 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/30 18:55:20 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		if (len > ft_strlen(s))
			len = ft_strlen(s) - start;
		j = 0;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		while (s[start] && j < len)
			str[j++] = s[start++];
		str[j] = '\0';
	}
	return (str);
}
