/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:00:02 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/21 13:33:56 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strttcpy(char *dest, char *src)

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

char	*ft_strdup(const char *src)

{
	char	*srrc;
	char	*dest;

	srrc = (char *)src;
	dest = (char *)malloc(sizeof(char) * ft_strlen(srrc) + 1);
	if (!dest)
		return (NULL);
	return (ft_strttcpy(dest, srrc));
}
