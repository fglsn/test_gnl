/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishakuro <ishakuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:58:36 by ishakuro          #+#    #+#             */
/*   Updated: 2021/11/15 17:50:08 by ishakuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char del)
{
	size_t	word;
	size_t	word_count;

	word = 0;
	word_count = 0;
	while (*s)
	{
		if (*s != del)
		{
			word++;
			if (word == 1)
				word_count++;
		}
		else
			word = 0;
		s++;
	}
	return (word_count);
}

static size_t	ft_word_length(char const *s, char del)
{
	size_t	len;

	len = 0;
	while (*s && *s != del)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**ft_split(char *s, char c, char **result)
{
	size_t	j;
	size_t	word_len;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		word_len = ft_word_length(s, c);
		if (!word_len)
			return (result);
		result[j] = ft_strnew(word_len);
		if (!result[j])
			return (NULL);
		ft_strncpy(result[j], s, word_len);
		s = s + word_len;
		j++;
	}
	return (result);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	words_count;

	if (!s)
		return (NULL);
	result = NULL;
	words_count = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(char *) * (words_count + 1));
	result = ft_split((char *)s, c, result);
	return (result);
}
