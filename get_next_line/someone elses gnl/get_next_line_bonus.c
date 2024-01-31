/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mewormse <mewormse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:03:52 by mewormse          #+#    #+#             */
/*   Updated: 2023/12/22 13:17:08 by mewormse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*str_read;
	int			byte;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 0)
		return (NULL);
	str_read = ft_calloc(1, 1);
	if (!line[fd])
		line[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (line[fd] && str_read)
	{
		str_read = ft_strjoin(str_read, line[fd]);
		if (end_of_line_cut(str_read, line[fd]))
			return (str_read);
		byte = read(fd, line[fd], BUFFER_SIZE);
		if (byte < 1)
		{
			free(line[fd]);
			line[fd] = NULL;
			if (str_read[0] != '\0')
				return (str_read);
			free(str_read);
			return (NULL);
		}
		line[fd][byte] = '\0';
	}
	return (str_read);
}
