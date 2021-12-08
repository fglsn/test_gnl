/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:21:44 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 12:08:07 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The strncat() function appends not more than n characters from s2,
** and then adds a terminating `\0'.
** The src and dest strings should not overlap, as the behavior is undefined.
** The strcat() and strncat() functions return the pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len < n)
	{
		ft_strcpy(&s1[s1_len], s2);
	}
	else
	{
		ft_strncpy(&s1[s1_len], s2, n);
		s1[s1_len + n] = '\0';
	}
	return (s1);
}
