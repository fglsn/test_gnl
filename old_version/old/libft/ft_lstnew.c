/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:37:42 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/30 12:20:08 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_node(void *data, size_t size)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		if (data)
			free(data);
		return (NULL);
	}
	node->content = data;
	node->content_size = size;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*content_copy;

	if (!content)
	{
		return (ft_create_node(NULL, 0));
	}
	content_copy = malloc(content_size);
	if (!content_copy)
		return (NULL);
	ft_memcpy(content_copy, content, content_size);
	return (ft_create_node(content_copy, content_size));
}
