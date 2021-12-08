/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:11:57 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 16:28:12 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The strcmp() and strncmp() functions lexicographically compare 
** the null-terminated strings s1 and s2.
** The strcmp() and strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than, 
** equal to, or less than the string s2.
** The strncmp() function compares not more than n characters.
** Because strncmp() is designed for comparing strings
** rather than binary data, characters that appear after a `\0' character
** are not compared.
** The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1 && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
