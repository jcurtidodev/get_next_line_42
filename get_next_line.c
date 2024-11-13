/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:07:42 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/14 12:58:37 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split_get_line(char **stash)
{
	char	*str;
	char	*pos;
	char	*temp;

	if (!*stash || !**stash)
		return (NULL);
	pos = ft_strchr(*stash, '\n');
	if (!pos)
	{
		str = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (str);
	}
	str = ft_substr(*stash, 0, pos - *stash + 1);
	temp = ft_strdup(pos + 1);
	free(*stash);
	*stash = temp;
	return (str);
}

static void	split_manage_stash(char **stash, char *buffer)
{
	char	*temp;

	if (*stash)
	{
		temp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = temp;
	}
	else
		*stash = ft_strdup(buffer);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*buffer;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		split_manage_stash(&stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read < 0 || (!stash && bytes_read == 0)
		|| (*stash == '\0' && bytes_read <= 0))
		return (free(stash), stash = NULL, NULL);
	return (split_get_line(&stash));
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i = 1;
	int fd;
	char *line;

	if (argc < 2)
		return (1);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error opening file");
			return (1);
		}
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		i++;
	}
	return (0);
}*/
