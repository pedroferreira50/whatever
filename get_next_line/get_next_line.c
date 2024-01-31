/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas- <pviegas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:41:49 by pviegas-          #+#    #+#             */
/*   Updated: 2023/11/14 16:04:56 by pviegas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_substring(char *main_str, size_t n)
{
	char	*new_str;

	if (main_str == NULL || n >= strlen(main_str))
	{
		free(main_str);
		return (NULL);
	}
	new_str = ft_strdup(main_str + n);
	free(main_str);
	return (new_str);
}

char	*read_loop_two(int fd, char *buffer, char *buffer_fd, int *read_line)
{
	char	*char_temp;

	while (*read_line > 0)
	{
		*read_line = read(fd, buffer, BUFFER_SIZE);
		if (*read_line == -1)
		{
			free(buffer_fd);
			return (NULL);
		}
		else if (*read_line == 0)
			break ;
		buffer[*read_line] = '\0';
		char_temp = buffer_fd;
		buffer_fd = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buffer_fd, '\n'))
			break ;
	}
	return (buffer_fd);
}

char	*read_loop(int fd, char *buffer, char *buffer_fd)
{
	int		read_line;

	read_line = 1;
	if (!buffer_fd)
	{
		buffer_fd = malloc(1);
		buffer_fd[0] = '\0';
	}
	buffer_fd = read_loop_two(fd, buffer, buffer_fd, &read_line);
	if (read_line == 0 && ft_strlen(buffer_fd) == 0)
	{
		free(buffer_fd);
		return (NULL);
	}
	return (buffer_fd);
}

char	*get_next_line_two(char	*buffer_fd, int fd, int *i)
{
	char		*buffer;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer_fd = read_loop(fd, buffer, buffer_fd);
	free(buffer);
	if (!buffer_fd)
		return (NULL);
	while (buffer_fd[(*i)] != '\0')
	{
		if (buffer_fd[(*i)] == '\n')
			break ;
		(*i)++;
	}
	return (buffer_fd);
}

char	*get_next_line(int fd)
{
	static char	*buffer_fd[4096];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	buffer_fd[fd] = get_next_line_two(buffer_fd[fd], fd, &i);
	if (!buffer_fd[fd])
		return (NULL);
	if (buffer_fd[fd][i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer_fd[fd], i + 1);
	line[i] = '\0';
	buffer_fd[fd] = remove_substring(buffer_fd[fd], i);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		len;
	char	*result;

	fd = open ("example.txt", O_RDONLY);
	len = 1;
	while (len < 10)
	{
		result = get_next_line(fd);
		printf("%i: %s$\n", len, result);
		free(result);
		len++;
	}
	close(fd);
	return (0);
}*/
