/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzafo <ybouzafo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:25:12 by ybouzafo          #+#    #+#             */
/*   Updated: 2023/10/21 14:52:18 by ybouzafo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

long long	ft_number(const char *str)
{
	int			i;
	long long	a;
	int			sign;

	i = 0;
	a = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (a * sign);
}

long long	ft_atoi(const char *str)
{
	long long	result;

	if (!ft_is_valid_number(str))
	{
		return (-1);
	}
	result = ft_number(str);
	if (result < -2147483648 || result > 2147483647)
	{
		return (-1);
	}
	return (result);
}
