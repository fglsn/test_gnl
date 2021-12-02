/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:39:36 by ishakuro          #+#    #+#             */
/*   Updated: 2021/12/02 14:10:28 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	char		*result = NULL;
	char		*result_copy = NULL;
	char		buff[BUFF_SIZE + 1];
	ssize_t		read_ret_val;
	static char	*prev[FD_COUNT];
	char		*prev_copy;
	char		*ptr_to_n;

	if (fd < 0 || line == NULL)
	{
		return (-1);
	}
	if (prev[fd])
	{
		ptr_to_n = ft_strchr(prev[fd], '\n');
		if (ptr_to_n)
		{
			*ptr_to_n = '\0';
			result = ft_strdup(prev[fd]);
			prev_copy = ft_strdup(ptr_to_n + 1);
			free(prev[fd]);
			prev[fd] = prev_copy;
			*line = result;
			return (1);
		}
		result = ft_strdup(prev[fd]);
		free(prev[fd]);
		prev[fd] = NULL;
	}
	read_ret_val = read(fd, buff, BUFF_SIZE);
	while (read_ret_val > 0)
	{
		buff[read_ret_val] = '\0';
		//printf("-%s-\n", buff);
		if (!result)
		{	
			ptr_to_n = ft_strchr(buff, '\n');
			//printf("$%s$\n", ptr_to_n + 1);
			if (ptr_to_n)
			{
				prev[fd] = ft_strdup(ptr_to_n + 1);
				*ptr_to_n = '\0';
				result = ft_strdup(buff);
				*line = result;
				return (1);
			}
			result = ft_strdup(buff);
		}
		else
		{
			ptr_to_n = ft_strchr(buff, '\n');
			if (ptr_to_n)
			{
				*ptr_to_n = '\0';
				result_copy = ft_strjoin(result, buff);
				free(result);
				result = result_copy;
				prev[fd] = ft_strdup(ptr_to_n + 1);
				*line = result;
				return (1);
			}
			result_copy = ft_strjoin(result, buff);
			free(result);
			result = result_copy;
		}
		read_ret_val = read(fd, buff, BUFF_SIZE);
	}
	if (read_ret_val < 0)
	{
		if (result)
			free(result);
		return (-1);
	}
	*line = result;
	if (prev[fd] == NULL && read_ret_val == 0 && (result == NULL || !ft_strlen(result)))
		return (0);
	return (1);
}
