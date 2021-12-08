/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:30:11 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 14:21:06 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strrchr() function locates the last occurrence of c (converted to a char)
** in the string pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is `\0', the functions locate the terminating `\0'.
** Returns a pointer to the located character, or NULL if no character found.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*ptr;

	ch = (char)c;
	ptr = NULL;
	while (*s)
	{
		if (*s == ch)
		{
			ptr = s;
		}
		s++;
	}
	if (*s == '\0' && ch == '\0')
	{
		return ((char *)s);
	}
	return ((char *)ptr);
}
