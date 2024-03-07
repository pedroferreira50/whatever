#include <stdlib.h>
#include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;
	int			byte;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE + 1);
		if (!buffer[fd])
        {
            free(line);
            return (NULL);
        }
		buffer[fd][0] = '\0';
	}
	while (buffer[fd] && line)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
            return (NULL);
		if (line_split(line, buffer[fd]))
			return (line);
		byte = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte < 1)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			if (line[0] != '\0' && byte != -1)
				return (line);
			free(line);
			return (NULL);
		}
		buffer[fd][byte] = '\0';
	}
	return (line);
}

/* int    main(void)
{
    char *line;
    int fd;
    fd = open("test.txt", O_RDONLY);
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
} */

