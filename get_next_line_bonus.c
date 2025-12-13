/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psilva-p <psilva-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:18:12 by psilva-p          #+#    #+#             */
/*   Updated: 2025/12/13 18:17:01 by psilva-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	char			*line;
	size_t			bytes_read;

	line = NULL;
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		buffer_move(buffer[fd]);
		bytes_read = linelen(line);
		if (!bytes_read || (line[bytes_read - 1] == '\n'))
			return (line);
	}
	return (line);
}

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	char *line;
// 	int		i = 0;
// 	int		j = 0;

// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return 1;
// 	}
// 	while (i < 1)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd2);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	while (i < 10)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 		{
// 			printf("line: %s", line);
// 			free(line);
// 		}
// 		i++;
// 	}
// 	close(fd);
// 	close(fd2);
// 	return 0;
// }
