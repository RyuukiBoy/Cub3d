/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:12:43 by ybouzafo          #+#    #+#             */
/*   Updated: 2022/11/03 20:55:35 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int r)
{
	char	*ptr;

	ptr = (char *)string;
	while (*ptr != (char)r && *ptr != '\0')
		ptr++;
	if (*ptr == (char)r)
		return (ptr);
	return (0);
}
