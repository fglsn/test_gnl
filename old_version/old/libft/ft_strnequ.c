/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:20:13 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/15 16:23:38 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2,	size_t n)
{
	if (s1 && s2)
	{
		if (!ft_strncmp(s1, s2, n))
		{
			return (1);
		}
	}
	return (0);
}
