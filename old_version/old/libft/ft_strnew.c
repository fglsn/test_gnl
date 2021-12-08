/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:53:18 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/05 16:42:43 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!new_str)
	{
		return (NULL);
	}
	ft_memset(new_str, (int) '\0', size + 1);
	return (new_str);
}
