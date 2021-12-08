/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:04:23 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/18 11:39:32 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION:
** The strcat() function appends a copy of the null-terminated string s2 
** to the end of the null-terminated string s1, then add a terminating `\0'.
** The string s1 must have sufficient space to hold the result.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy((s1 + ft_strlen(s1)), s2);
	return (s1);
}
