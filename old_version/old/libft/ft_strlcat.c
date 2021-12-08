/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:11:17 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/22 11:03:00 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** Strlcat() copies and concatenates strings with the same input parameters
** and output result as snprintf(3).
** Strlcat() take the full size of the destination buffer and guarantee
** NUL-termination if there is room.
** Note that room for the NUL should be included in dstsize.
** Strlcat() function returns the total length of the string it tried to create.
** That means the initial length of dst plus the length of src.
** If the return value is >= dstsize, the output string has been truncated.
** It is the caller's responsibility to handle this.
** Note, that if strlcat() traverses size characters without finding a NUL,
** the length of the string is considered to be size and the destination
** string will not be NUL-terminated (since there was no space for the NUL). 
** This keeps strlcat() from running off the end of a string. 
** In practice this should not happen (as it means that either size is incorrect
** or that dst is not a proper ''C'' string). 
** The check exists to prevent potential security problems in incorrect code.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	if (!dst && !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
	{
		return (src_len + dstsize);
	}
	else
	{
		dst = dst + dst_len;
		ft_strlcpy(dst, src, dstsize - dst_len);
		return (dst_len + src_len);
	}
}
