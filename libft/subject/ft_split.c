/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:51:21 by fl-hote           #+#    #+#             */
/*   Updated: 2022/03/10 19:26:37 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(const char *str, const char c)
{
	int	i;
	int	is_word;

	i = 0;
	if (ft_isprint(c))
	{
		is_word = 0;
		while (*str)
		{
			if ((*str == c) == is_word)
			{
				is_word = 1 - is_word;
				if (is_word)
					i++;
			}
			str++;
		}
	}
	else
		i = 1;
	return (i);
}

/* On alloc error, free current and prec lines, then free tab */
static char	**free_on_error(char **tab, unsigned int i)
{
	while (--i)
		free(tab[i]);
	free(tab);
	return (NULL);
}

/* ft_calloc avoid to write NULL for last elem */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i_word;
	size_t	i;

	tab = ft_calloc((count_w(s, c) + 1), sizeof(char *));
	
	if (!tab)
		return (NULL);
	i_word = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			tab[i_word] = malloc(sizeof(char) * (i + 1));
			if (!tab[i_word])
				return (free_on_error(tab, i_word + 1));
			ft_strlcpy(tab[i_word++], s, i + 1);
			s += i;
		}
	}
	return (tab);
}
