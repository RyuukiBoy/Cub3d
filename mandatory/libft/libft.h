/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:59:40 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/12/25 12:00:22 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_is_digit(char c);
int			ft_is_valid_number(const char *str);
long long	ft_atoi(const char *str);
long long	ft_number(const char *str);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *string, int r);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
#endif
