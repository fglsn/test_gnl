/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:16:24 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/17 15:38:44 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The memccpy() function copies bytes from string src to string dst.
** If the character c (converted to an unsigned char) occurs in the string src,
** the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;

	source = (const unsigned char *)src;
	dest = (unsigned char *)dst;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*source == ch)
		{
			*dest++ = *source++;
			return (dest);
		}
		*dest++ = *source++;
		i++;
	}
	return (NULL);
}
