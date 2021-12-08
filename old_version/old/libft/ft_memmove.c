/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:40:52 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/22 21:37:18 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The memmove() function copies len bytes from string src to string dst.
** Strings may overlap; the copy is always done in a non-destructive manner.
** The memmove() function returns the original value of dst.
*/

#include "libft.h"

static int	ft_detect_overlap(char *start, size_t len, char *ptr)
{
	while (len > 0)
	{
		if (start + len - 1 == ptr)
		{
			return (1);
		}
		len--;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst || !src)
	{
		return (NULL);
	}
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!len)
	{
		return (dst);
	}
	if (ft_detect_overlap((char *)source, len, (char *)dest))
	{
		while (len > 0)
		{
			*(dest + len - 1) = *(source + len - 1);
			len--;
		}
		return (dst);
	}
	ft_memcpy(dest, source, len);
	return (dst);
}
