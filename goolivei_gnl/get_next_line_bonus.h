/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:50 by goolivei          #+#    #+#             */
/*   Updated: 2024/01/18 11:57:52 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*buffer_full_clear(int fd, char **buffer, char *line);
int		next_line(char **line, char *buffer);
void	buffer_clear(char *buffer);
char	*ft_strjoin2(char const *str1, char const *str2);
int		ft_strlen2(char const *str);

#endif
