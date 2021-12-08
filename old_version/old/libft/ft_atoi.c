/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:57:33 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/22 13:57:36 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char **c)
{
	if (**c == '+')
	{
		*c = *c + 1;
		return (1);
	}
	else if (**c == '-')
	{
		*c = *c + 1;
		return (-1);
	}
	return (1);
}

static int	handle_overflow(int sign)
{
	long	long_max;
	long	long_min;

	long_max = (2 >> 31) - 1;
	long_min = -(2 >> 31);
	if (sign > 0)
	{
		return ((int)long_max);
	}
	else
	{
		return ((int)long_min);
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = check_sign(&str);
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result < 0)
		{
			return (handle_overflow(sign));
		}
		str++;
	}
	return ((int)result * sign);
}
