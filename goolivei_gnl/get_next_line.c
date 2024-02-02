/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:55:29 by goolivei          #+#    #+#             */
/*   Updated: 2024/01/18 11:55:33 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			read_line;

	line = NULL;
	if (fd < 0 || fd >= FOPEN_MAX)
		return (buffer_full_clear(fd, (char **)buffer, line));
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read_line = read(fd, buffer, BUFFER_SIZE);
			if (read_line == -1)
				return (buffer_full_clear(fd, NULL, line));
			if (read_line == 0)
				return (line);
		}
		flag = next_line(&line, buffer);
		buffer_clear(buffer);
		if (flag == 1)
			return (line);
		if (flag == -1)
			return (NULL);
	}
}
/*
int    main(void)
{
    char *line;
    int fd;
    fd = open("insert.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
