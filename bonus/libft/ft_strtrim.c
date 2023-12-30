/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:33:29 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/28 10:41:05 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*nv;
	size_t	len;
	size_t	i;

	if (!set)
		return ((char *)s1);
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	str = (char *)s1;
	while (str[i] != '\0' && ft_strchr(set, str[i]))
		i++;
	while (len > i + 1 && ft_strchr(set, str[len - 1]))
		len--;
	nv = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!nv)
		return (NULL);
	ft_strlcpy(nv, str + i, len - i + 1);
	return (nv);
}

char	*ft_strtrim_to_free(char *str, char *ptr)
{
	char	*tempo;

	if (!str)
		return (NULL);
	tempo = ft_strtrim(str, ptr);
	free(str);
	return (tempo);
}
