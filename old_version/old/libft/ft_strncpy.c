/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:02:04 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 11:07:35 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The strncpy() function copies at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst
** is filled with `\0' characters.  Otherwise, dst is not terminated.
** Returns dst.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (len > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
