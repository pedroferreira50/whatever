/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:13 by goolivei          #+#    #+#             */
/*   Updated: 2024/02/01 13:55:14 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			read_line;

	line = NULL;
	if (fd < 0 || fd >= FOPEN_MAX)
		return (buffer_full_clear(fd, (char **)buffer[fd], line));
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			read_line = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_line == -1)
				return (buffer_full_clear(fd, NULL, line));
			if (read_line == 0)
				return (line);
		}
		flag = next_line(&line, buffer[fd]);
		buffer_clear(buffer[fd]);
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
    int fd[2];
    fd[0] = open("gojo.txt", O_RDONLY);
    if (fd[0] == -1)
    {
        perror("Error");
        return (1);
    }
    while ((line = get_next_line(fd[0])) != NULL)
    {
        printf("line: %s\n", line);
        free(line);
    }
    close(fd[0]);
    fd[1] = open("hakari.txt", O_RDONLY);
    if (fd[1] == -1)
    {
        perror("Error");
        return (1);
    }
    while ((line = get_next_line(fd[1])) != NULL)
    {
        printf("line: %s\n", line);
        free(line);
    }
    close(fd[1]);
    return (0);
}*/
