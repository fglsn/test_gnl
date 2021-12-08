/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:36:10 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 14:27:17 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
** If needle is an empty string, haystack is returned;
** If needle occurs nowhere in haystack, NULL is returned; 
** Otherwise a pointer to the first character
** of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	stack_len;
	size_t	needle_len;

	i = 0;
	stack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (stack_len < needle_len)
		return (NULL);
	while (i <= stack_len - needle_len)
	{
		j = 0;
		while (haystack[j + i] == needle[j] && j < needle_len)
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
