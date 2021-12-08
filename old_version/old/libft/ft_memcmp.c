/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:39:37 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/17 16:31:25 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The memcmp() compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** Returns 0 if the two strings are identical, 
** otherwise returns the difference between the first two differing bytes 
** (treated as unsigned char values, so that `\200' > `\0')
** Zero-length strings are always identical. 
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (i < n)
	{
		if (*str1++ != *str2++)
		{
			return (*--str1 - *--str2);
		}
		i++;
	}
	return (0);
}
