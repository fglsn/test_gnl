/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:16:45 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/17 17:11:54 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The strdup() function allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function free(3).
** If insufficient memory is available, NULL is returned
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s1) + 1;
	copy = (char *)malloc(len * sizeof(char));
	if (!copy)
	{
		return (NULL);
	}
	return ((char *)ft_memcpy(copy, s1, len));
}
