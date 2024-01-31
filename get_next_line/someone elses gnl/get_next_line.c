/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mewormse <mewormse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:33:09 by mewormse          #+#    #+#             */
/*   Updated: 2024/01/03 11:13:28 by mewormse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str_read;
	int			byte;

	str_read = ft_calloc(1, 1);
	if (!line)
		line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (line && str_read)
	{
		str_read = ft_strjoin(str_read, line);
		if (end_of_line_cut(str_read, line))
			return (str_read);
		byte = read(fd, line, BUFFER_SIZE);
		if (byte < 1)
		{
			free(line);
			line = NULL;
			if (str_read[0] != '\0')
				return (str_read);
			free(str_read);
			return (NULL);
		}
		line[byte] = '\0';
	}
	return (str_read);
}