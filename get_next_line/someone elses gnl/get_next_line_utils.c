/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mewormse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:51:10 by mewormse          #+#    #+#             */
/*   Updated: 2023/12/16 16:37:10 by mewormse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	free (s1);
	return (s3);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	if (nmemb == 0 || size == 0)
	{
		arr = malloc(1);
		if (!arr)
			return (NULL);
		arr[0] = '\0';
		return (arr);
	}
	if ((long long)nmemb < 0 || (long long)size < 0)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

int	end_of_line_cut(char *str_read, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str_read[i] && str_read[i] != '\n')
		i++;
	if (str_read[i] == '\n')
	{
		i++;
		while (str_read[i])
		{
			line[j] = str_read[i];
			i++;
			j++;
		}
		line[j] = '\0';
		str_read[i - j] = '\0';
		return (1);
	}
	return (0);
}
