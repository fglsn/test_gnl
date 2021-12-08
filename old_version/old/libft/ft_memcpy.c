/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:20:42 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/17 15:35:50 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The memcpy() function copies n bytes from memory src to memory dst.
** If src and dst overlap, behavior is undefined.  Applications in which
** src and dst might overlap should use memmove(3) instead.
** The memcpy() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (!s && !d)
		return (NULL);
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dst);
}
