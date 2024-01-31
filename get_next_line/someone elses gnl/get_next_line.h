/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mewormse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:04:23 by mewormse          #+#    #+#             */
/*   Updated: 2023/12/18 16:04:38 by mewormse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		end_of_line_cut(char *str_read, char *line);
size_t	ft_strlen(char *s);

#endif
