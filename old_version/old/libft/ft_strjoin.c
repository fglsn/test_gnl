/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:03:32 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/22 11:02:01 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_s_len(char const *s)
{
	size_t	len;

	if (s)
		len = ft_strlen(s);
	else
		len = 0;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*start;
	size_t	len_1;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	len_1 = ft_s_len(s1);
	len_2 = ft_s_len(s2);
	result = ft_strnew(len_1 + len_2);
	if (!result)
		return (NULL);
	start = result;
	if (s1)
		while (*s1)
			*result++ = *s1++;
	if (s2)
		while (*s2)
			*result++ = *s2++;
	return (start);
}
