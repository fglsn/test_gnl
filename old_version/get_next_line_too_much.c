/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:39:36 by ishakuro          #+#    #+#             */
/*   Updated: 2021/12/05 21:56:50 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	join_and_free(char **s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = temp;
}

static int	check_prev(char **prev, char **line)
{
	char	*ptr_to_n;
	char	*temp;

	if (!(*prev))
		return (0);
	ptr_to_n = ft_strchr(*prev, '\n');
	if (ptr_to_n)
	{
		temp = ft_strdup(ptr_to_n + 1);
		*ptr_to_n = '\0';
		if (*line)
			join_and_free(line, *prev);
		else
		{
			*line = ft_strdup(*prev);
			free(*prev);
			*prev = temp;
		}
		return (1);
	}
	*line = ft_strdup(*prev);
	ft_memdel((void **)prev);
	return (0);
}

static int	save_line(char **prev, int buf_len, char **line)
{
	if (buf_len < 0)
	{
		ft_memdel((void **)prev);
		return (-1);
	}
	if (buf_len == 0 && (!(*line) || !ft_strlen(*line)) && (*prev == NULL || !ft_strlen(*prev)))
	{	
		ft_memdel((void **)prev);
		return (0);
	}
	check_prev(prev, line);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*prev[FD_COUNT];
	char		buff[BUFF_SIZE + 1];
	ssize_t		buf_len;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (check_prev(&prev[fd], line))
		return (1);
	buf_len = read(fd, buff, BUFF_SIZE);
	while (buf_len > 0)
	{
		buff[buf_len] = '\0';
		if (!prev[fd])
			prev[fd] = ft_strdup(buff);
		else
			join_and_free(&prev[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
		buf_len = read(fd, buff, BUFF_SIZE);
	}
	return (save_line(&prev[fd], buf_len, line));
}
